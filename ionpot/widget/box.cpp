#include "box.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <sdl/point_in_rect.hpp>

#include <optional>

namespace ionpot::widget {
	Box::Box(util::Size size, util::Point pos):
		m_position {pos},
		m_size {size}
	{}

	void
	Box::add_x(int amount)
	{
		m_position.x += amount;
	}

	void
	Box::add_y(int amount)
	{
		m_position.y += amount;
	}

	void
	Box::center_to(const Box& box)
	{
		m_position = box.size().center(size()) + box.position();
	}

	bool
	Box::contains(util::Point p, util::Point offset) const
	{
		return sdl::point_in_rect(m_position + offset, m_size, p);
	}

	util::Point
	Box::max_point() const
	{
		return position() + util::Point {size()};
	}

	void
	Box::place_after(const Box& box, int spacing)
	{
		place_on(box);
		add_x(box.size().width + spacing);
	}

	void
	Box::place_below(const Box& box, int spacing)
	{
		place_on(box);
		add_y(box.size().height + spacing);
	}

	void
	Box::place_on(const Box& box)
	{
		m_position = box.position();
	}

	void
	Box::position(util::Point p)
	{
		m_position = p;
	}

	util::Point
	Box::position() const
	{
		return m_position;
	}

	util::Size
	Box::size() const
	{
		return m_size;
	}

	void
	Box::size(util::Size size)
	{
		m_size = size;
	}

	// helpers
	util::Point
	min_point(const std::vector<const Box*>& boxes)
	{
		std::optional<util::Point> min;
		for (auto box : boxes) {
			auto p = box->position();
			if (min)
				min->pick_min(p);
			else
				min = p;
		}
		return min.value_or(util::Point {});
	}

	util::Point
	max_point(const std::vector<const Box*>& boxes)
	{
		std::optional<util::Point> max;
		for (auto box : boxes) {
			auto p = box->max_point();
			if (max)
				max->pick_max(p);
			else
				max = p;
		}
		return max.value_or(util::Point {});
	}

	template<>
	util::Size
	sum_sizes(const std::vector<const Box*>& boxes)
	{
		auto min = min_point(boxes);
		auto max = max_point(boxes);
		return util::Size {min.diff(max)};
	}
}
