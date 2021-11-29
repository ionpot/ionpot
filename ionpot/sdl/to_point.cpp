#include "to_point.hpp"

#include <util/point.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	SDL_Point
	to_point(util::Point p)
	{
		SDL_Point point;
		point.x = p.x;
		point.y = p.y;
		return point;
	}
}
