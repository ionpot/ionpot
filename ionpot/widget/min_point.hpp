#pragma once

#include <util/point.hpp>

namespace ionpot::widget {
	template<class T> // T = Box[]
	util::Point
	min_point(const T& boxes)
	{
		util::Point min;
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
