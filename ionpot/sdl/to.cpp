#include "to.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

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

	SDL_Rect
	to_rect(util::Point pos, util::Size size)
	{
		SDL_Rect rect;
		rect.x = pos.x;
		rect.y = pos.y;
		rect.w = size.width;
		rect.h = size.height;
		return rect;
	}
}
