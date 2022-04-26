#pragma once

#include <util/point.hpp>

namespace ionpot::widget {
	template<class T> // T = Box[]
	util::Point
	max_point(const T& boxes)
	{
		util::Point max;
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
