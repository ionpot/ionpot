#pragma once

#include "min_point.hpp"
#include "max_point.hpp"

#include <util/size.hpp>

namespace ionpot::widget {
	template<class T> // T = Box[]
	util::Size
	sum_sizes(const T& boxes)
	{
		auto min = min_point(boxes);
		auto max = max_point(boxes);
		return util::Size {min.diff(max)};
	}
}
