#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::sdl {
	bool point_in_rect(
			util::Point rect_pos,
			util::Size rect_size,
			util::Point point);
}
