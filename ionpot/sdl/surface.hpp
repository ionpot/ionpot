#pragma once

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	struct Surface {
		SDL_Surface* pointer;

		Surface() = default;
		~Surface();
		IONPOT_NO_COPY(Surface)
		IONPOT_DEFAULT_MOVE(Surface)
	};
}
