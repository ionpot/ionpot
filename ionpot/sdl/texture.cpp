#include "texture.hpp"

#include "exception.hpp"
#include "surface.hpp"

#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	Texture::Texture(SDL_Texture* texture, util::Size size):
		size {size},
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
		if (SDL_QueryTexture(m_texture, NULL, NULL, &size.width, &size.height))
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
		size {from.size},
		m_texture {from.m_texture}
	{
		from.m_texture = NULL;
	}

	Texture&
	Texture::operator=(Texture&& from) noexcept
	{
		size = from.size;
		m_texture = from.m_texture;
		from.m_texture = NULL;
		return *this;
	}

	TargetTexture::TargetTexture(SDL_Renderer* renderer, util::Size size):
		Texture {renderer, size, SDL_TEXTUREACCESS_TARGET}
	{}
}
