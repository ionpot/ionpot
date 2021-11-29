#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::sdl {
	struct Hexagon {
		int side;
		int x1, x2, x3;
		int y1, y2;
		util::Point center;

		Hexagon(double side);

		util::Size size() const;
		int height() const;
		int width() const;

		bool contains(util::Point) const;

		// clockwise from top left
		util::Point point1() const;
		util::Point point2() const;
		util::Point point3() const;
		util::Point point4() const;
		util::Point point5() const;
		util::Point point6() const;
	};
}
