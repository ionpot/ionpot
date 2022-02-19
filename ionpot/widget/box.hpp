#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	class Box {
	public:
		virtual ~Box() {}

		virtual Size size() const = 0;

		virtual const Box* contains(Point) const;

		void position(Point);
		Point position() const;

		void add_x(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing);
		void place_on(const Box&);

	protected:
		Point m_position;
	};
}
