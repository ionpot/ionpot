#include "surface.hpp"

#include <SDL.h>

namespace ionpot::sdl {
	Surface::~Surface()
	{
		if (pointer) {
			SDL_FreeSurface(pointer);
			pointer = NULL;
		}
	}
}
