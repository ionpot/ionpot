#include "box.hpp"

#include "point.hpp"
#include "size.hpp"

#include <sdl/point_in_rect.hpp>

namespace ionpot::widget {
	Box::Box(Size size, Point pos):
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

	const Box*
	Box::contains(Point p) const
	{
		if (sdl::point_in_rect(m_position, size(), p)) {
			return this;
		}
		return nullptr;
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
	Box::position(Point p)
	{
		m_position = p;
	}

	Point
	Box::position() const
	{
		return m_position;
	}

	Size
	Box::size() const
	{
		return m_size;
	}
}
