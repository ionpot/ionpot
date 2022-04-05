#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	class Box {
	public:
		Box(Size, Point pos = {0});

		const Box* contains(Point) const;

		void position(Point);
		Point position() const;

		Size size() const;

		void add_x(int amount);
		void add_y(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing);
		void place_below(const Box&, int spacing);
		void place_on(const Box&);

	private:
		Point m_position;
		Size m_size;
	};
}
