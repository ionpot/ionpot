#pragma once

#include "point.hpp"

namespace ionpot::widget {
	template<class T> // T = Box[]
	Point
	max_point(const T& boxes)
	{
		Point max;
		auto box = boxes.begin();
		if (box < boxes.end()) {
			max = box->max_point();
		}
		while (++box < boxes.end()) {
			max.pick_max(box->max_point());
		}
		return max;
	}
}
