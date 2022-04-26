#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	SDL_Point to_point(util::Point);
	SDL_Rect to_rect(util::Point, util::Size);
}
