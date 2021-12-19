#include "texture.hpp"

#include "exception.hpp"
#include "surface.hpp"

#include <util/size.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr, std::static_pointer_cast

namespace ionpot::sdl {
	Texture::Texture(SDL_Texture* texture, util::Size size):
		m_size {size},
		m_texture {texture}
	{
		if (!m_texture)
			throw Exception {};
		if (SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND))
			throw Exception {};
	}

	Texture::Texture(SDL_Renderer* renderer, util::Size size, Uint32 flags):
		Texture {
			SDL_CreateTexture(
				renderer,
				SDL_PIXELFORMAT_RGBA8888,
				flags,
				size.width, size.height),
			size}
	{}

	Texture::Texture(SDL_Renderer* renderer, const Surface& surface):
		Texture {SDL_CreateTextureFromSurface(renderer, surface.pointer)}
	{
		if (SDL_QueryTexture(m_texture, NULL, NULL, &m_size.width, &m_size.height))
			throw Exception {};
	}

	Texture::~Texture()
	{
		if (m_texture) {
			SDL_DestroyTexture(m_texture);
			m_texture = NULL;
		}
	}

	Texture::Texture(Texture&& from) noexcept:
		m_size {from.size()},
		m_texture {from.m_texture}
	{
		from.m_texture = NULL;
	}

	Texture&
	Texture::operator=(Texture&& from) noexcept
	{
		m_size = from.size();
		m_texture = from.m_texture;
		from.m_texture = NULL;
		return *this;
	}

	util::Size
	Texture::size() const
	{ return m_size; }

	// TargetTexture
	TargetTexture::TargetTexture(SDL_Renderer* renderer, util::Size size):
		Texture {renderer, size, SDL_TEXTUREACCESS_TARGET}
	{}

	// SharedTexture
	SharedTexture::SharedTexture(std::shared_ptr<Texture> ptr):
		m_texture {ptr}
	{}

	SharedTexture::SharedTexture(std::shared_ptr<TargetTexture> ptr):
		m_texture {std::static_pointer_cast<Texture>(ptr)}
	{}

	const Texture&
	SharedTexture::get() const
	{ return *m_texture; }

	util::Size
	SharedTexture::size() const
	{ return m_texture->size(); }
}
