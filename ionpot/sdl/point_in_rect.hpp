#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::sdl {
	bool point_in_rect(Point rect_pos, Size rect_size, Point point);
}
