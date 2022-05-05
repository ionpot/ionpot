#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

#include <optional>

namespace ionpot::widget {
	class Box {
	public:
		Box(util::Size = {}, util::Point pos = {});

		bool contains(util::Point, util::Point offset = {}) const;

		util::Point max_point() const;

		void position(util::Point);
		util::Point position() const;

		util::Size size() const;

		void add_x(int amount);
		void add_y(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing = 0);
		void place_after(util::Size, int spacing = 0);
		void place_below(const Box&, int spacing = 0);
		void place_on(const Box&);

	protected:
		void size(util::Size);

	private:
		util::Point m_position;
		util::Size m_size;
	};

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
