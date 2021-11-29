#include "rect.hpp"

#include "to_point.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	Rect::Rect(util::Size s):
		position {0, 0},
		size {s}
	{}

	Rect::Rect(util::Point p, util::Size s):
		position {p},
		size {s}
	{}

	bool
	Rect::contains(util::Point p) const
	{
		auto rect = to_sdl();
		auto point = to_point(p);
		return SDL_PointInRect(&point, &rect) == SDL_TRUE;
	}

	SDL_Rect
	Rect::to_sdl() const
	{
		SDL_Rect rect;
		rect.x = position.x;
		rect.y = position.y;
		rect.w = size.width;
		rect.h = size.height;
		return rect;
	}
}
