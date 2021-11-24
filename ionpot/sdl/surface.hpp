#pragma once

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	struct Surface {
		SDL_Surface* pointer;

		Surface(SDL_Surface*);
		~Surface();
		IONPOT_NO_COPY(Surface)
		IONPOT_DECLARE_MOVE(Surface)
	};
}
