#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

#include <optional>

namespace ionpot::widget {
	template<class T> // T = Element[]
	util::Point
	min_point(const T& elements)
	{
		std::optional<util::Point> min;
		for (const auto& elmt : elements) {
			if (elmt.hidden())
				continue;
			auto p = elmt.position();
			if (min)
				min->pick_min(p);
			else
				min = p;
		}
		return min.value_or(util::Point {});
	}

	template<class T> // T = Element[]
	util::Point
	max_point(const T& elements)
	{
		std::optional<util::Point> max;
		for (const auto& elmt : elements) {
			if (elmt.hidden())
				continue;
			auto p = elmt.max_point();
			if (max)
				max->pick_max(p);
			else
				max = p;
		}
		return max.value_or(util::Point {});
	}

	template<class T> // T = Element[]
	util::Size
	sum_sizes(const T& elements)
	{
		auto min = min_point(elements);
		auto max = max_point(elements);
		return util::Size {min.diff(max)};
	}
}
