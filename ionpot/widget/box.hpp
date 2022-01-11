#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	struct Box {
		virtual ~Box() {}

		virtual void position(Point) = 0;
		virtual Point position() const = 0;

		virtual Size size() const = 0;

		virtual const Box* contains(Point) const;

		void add_x(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing);
		void place_on(const Box&);
	};
}
