#include "box.hpp"

#include "point.hpp"

#include <sdl/point_in_rect.hpp>

namespace ionpot::widget {
	void
	Box::add_x(int amount)
	{
		auto [x, y] = position();
		position(Point {x + amount, y});
	}

	void
	Box::center_to(const Box& box)
	{
		position(box.size().center(size()) + box.position());
	}

	const Box*
	Box::contains(Point p) const
	{
		if (sdl::point_in_rect(position(), size(), p)) {
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
	Box::place_on(const Box& box)
	{
		position(box.position());
	}
}
