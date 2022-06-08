#include "sum_sizes.hpp"

#include "element.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <optional>
#include <vector>

namespace ionpot::widget {
	namespace {
		util::Point
		min_point(const std::vector<Element>& ls)
		{
			std::optional<util::Point> min;
			for (const auto& elmt : ls) {
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

		util::Point
		max_point(const std::vector<Element>& ls)
		{
			std::optional<util::Point> max;
			for (const auto& elmt : ls) {
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
	}

	util::Size
	sum_sizes(const std::vector<Element>& ls)
	{
		auto min = min_point(ls);
		auto max = max_point(ls);
		return util::Size {min.diff(max)};
	}
}
