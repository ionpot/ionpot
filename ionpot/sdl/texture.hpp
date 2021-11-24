#pragma once

#include "size.hpp"
#include "surface.hpp"

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	class Texture {
	public:
		Size size;
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)
	protected:
		friend class Renderer;
		SDL_Texture* m_texture;
		Texture(SDL_Texture*, Size = {});
		Texture(SDL_Renderer*, Size, Uint32 flags);
		Texture(SDL_Renderer*, const Surface&);
	};

	class TargetTexture : public Texture {
		friend class Renderer;
		TargetTexture(SDL_Renderer*, Size);
	};
}
