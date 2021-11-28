#pragma once

#include "surface.hpp"

#include <util/macros.hpp>
#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	class Texture {
	public:
		util::Size size;
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)
	protected:
		friend class Renderer;
		SDL_Texture* m_texture;
		Texture(SDL_Texture*, util::Size = {});
		Texture(SDL_Renderer*, util::Size, Uint32 flags);
		Texture(SDL_Renderer*, const Surface&);
	};

	class TargetTexture : public Texture {
		friend class Renderer;
		TargetTexture(SDL_Renderer*, util::Size);
	};
}
