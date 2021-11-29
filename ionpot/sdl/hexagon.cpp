#include "hexagon.hpp"

#include <util/int.hpp>
#include <util/point.hpp>
#include <util/size.hpp>

#include <algorithm>
#include <cmath>

namespace ionpot::sdl {
	namespace {
		const double s_sqrt3 = std::sqrt(3);

		int s_round1(double d)
		{
			return std::max(1, IONPOT_INT_ROUND(d));
		}
	}

	Hexagon::Hexagon(double a_side):
		side {IONPOT_INT_POSITIVE(IONPOT_INT_ROUND(a_side))},
		x1 {s_round1(a_side / 2)},
		x2 {x1 + side - 1},
		x3 {x1 + x2},
		y1 {s_round1(a_side / 2 * s_sqrt3)},
		y2 {y1 * 2},
		center {(x3 + 1) / 2, (y2 + 1) / 2}
	{
	}

	bool Hexagon::contains(util::Point p) const
	{
		auto r = static_cast<double>(center.x);
		return p.distance(center) <= r;
	}

	util::Point Hexagon::point1() const
	{
		return {x1, 0};
	}

	util::Point Hexagon::point2() const
	{
		return {x2, 0};
	}

	util::Point Hexagon::point3() const
	{
		return {x3, y1};
	}

	util::Point Hexagon::point4() const
	{
		return {x2, y2};
	}

	util::Point Hexagon::point5() const
	{
		return {x1, y2};
	}

	util::Point Hexagon::point6() const
	{
		return {0, y1};
	}

	util::Size Hexagon::size() const
	{
		return {width(), height()};
	}

	int Hexagon::height() const
	{
		return y2 + 1;
	}

	int Hexagon::width() const
	{
		return x3 + 1;
	}
}
