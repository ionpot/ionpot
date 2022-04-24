#pragma once

#include "point.hpp"

namespace ionpot::widget {
	template<class T> // T = Box[]
	Point
	min_point(const T& boxes)
	{
		Point min;
		auto box = boxes.begin();
		if (box < boxes.end()) {
			min = box->position();
		}
		while (++box < boxes.end()) {
			min.pick_min(box->position());
		}
		return min;
	}
}
