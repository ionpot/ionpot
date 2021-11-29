#pragma once

#include <util/point.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	SDL_Point to_point(util::Point);
}
