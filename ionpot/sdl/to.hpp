#pragma once

#include "point.hpp"
#include "size.hpp"

#include <SDL.h>

namespace ionpot::sdl {
	SDL_Point to_point(Point);
	SDL_Rect to_rect(Point, Size);
}
