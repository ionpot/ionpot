#include "point_in_rect.hpp"

#include "to.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	bool
	point_in_rect(
			util::Point rect_pos,
			util::Size rect_size,
			util::Point p)
	{
		auto point = to_point(p);
		auto rect = to_rect(rect_pos, rect_size);
		return SDL_PointInRect(&point, &rect) == SDL_TRUE;
	}
}
