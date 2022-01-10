#include "texture.hpp"

#include "exception.hpp"
#include "renderer.hpp"
#include "size.hpp"
#include "surface.hpp"
#include "to.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	Texture::Texture(std::shared_ptr<Renderer> rdr, SDL_Texture* tx):
		m_renderer {rdr},
		m_texture {tx}
	{
		if (!m_texture)
			throw Exception {};
	}

	Texture::Texture(std::shared_ptr<Renderer> rdr, Size size, Uint32 flags):
		Texture {rdr,
			SDL_CreateTexture(
				rdr->m_renderer,
				SDL_PIXELFORMAT_RGBA8888,
				flags,
				size.width, size.height)
		}
	{}

	Texture::Texture(std::shared_ptr<Renderer> rdr, const Surface& surface):
		Texture {
			rdr,
			SDL_CreateTextureFromSurface(rdr->m_renderer, surface.pointer)
		}
	{}

	Texture::~Texture()
	{
		if (m_texture) {
			SDL_DestroyTexture(m_texture);
			m_texture = NULL;
		}
	}

	Texture::Texture(Texture&& from) noexcept:
		m_renderer {from.m_renderer},
		m_texture {from.m_texture}
	{
		from.m_texture = NULL;
	}

	Texture&
	Texture::operator=(Texture&& from) noexcept
	{
		m_renderer = from.m_renderer;
		m_texture = from.m_texture;
		from.m_texture = NULL;
		return *this;
	}

	Size
	Texture::query_size() const
	{
		int width {0};
		int height {0};
		if (SDL_QueryTexture(m_texture, NULL, NULL, &width, &height))
			throw Exception {};
		return {width, height};
	}

	void
	Texture::render(Point dst_pos, Size dst_size) const
	{
		auto dst = to_rect(dst_pos, dst_size);
		if (SDL_RenderCopy(m_renderer->m_renderer, m_texture, NULL, &dst))
			throw Exception {};
	}

	void
	Texture::render(
			Point dst_pos,
			Size dst_size,
			Point src_pos,
			Size src_size) const
	{
		auto src = to_rect(src_pos, src_size);
		auto dst = to_rect(dst_pos, dst_size);
		if (SDL_RenderCopy(m_renderer->m_renderer, m_texture, &src, &dst))
			throw Exception {};
	}

	void
	Texture::set_blend() const
	{
		if (SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND))
			throw Exception {};
	}

	// TargetTexture
	TargetTexture::TargetTexture(std::shared_ptr<Renderer> rdr, Size size):
		Texture {rdr, size, SDL_TEXTUREACCESS_TARGET}
	{}

	const Renderer&
	TargetTexture::set_as_target() const
	{
		const auto& rdr = *m_renderer;
		if (SDL_SetRenderTarget(rdr.m_renderer, m_texture))
			throw Exception {};
		return rdr;
	}
}
