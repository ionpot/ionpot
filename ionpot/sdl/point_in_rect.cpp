#include "point_in_rect.hpp"

#include "point.hpp"
#include "size.hpp"
#include "to.hpp"

#include <SDL.h>

namespace ionpot::sdl {
	bool
	point_in_rect(Point rect_pos, Size rect_size, Point p)
	{
		auto point = to_point(p);
		auto rect = to_rect(rect_pos, rect_size);
		return SDL_PointInRect(&point, &rect) == SDL_TRUE;
	}
}
