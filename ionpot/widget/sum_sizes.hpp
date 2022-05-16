#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

#include <optional>

namespace ionpot::widget {
	template<class T> // T = Box[]
	util::Point
	min_point(const T& boxes)
	{
		std::optional<util::Point> min;
		for (const auto& box : boxes) {
			auto p = box.position();
			if (min)
				min->pick_min(p);
			else
				min = p;
		}
		return min.value_or(util::Point {});
	}

	template<class T> // T = Box[]
	util::Point
	max_point(const T& boxes)
	{
		std::optional<util::Point> max;
		for (const auto& box : boxes) {
			auto p = box.max_point();
			if (max)
				max->pick_max(p);
			else
				max = p;
		}
		return max.value_or(util::Point {});
	}

	template<class T> // T = Box[]
	util::Size
	sum_sizes(const T& boxes)
	{
		auto min = min_point(boxes);
		auto max = max_point(boxes);
		return util::Size {min.diff(max)};
	}
}
