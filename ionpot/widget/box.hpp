#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	class Box {
	public:
		Box(Size, Point pos = {});

		bool contains(Point, Point offset = {}) const;

		Point max_point() const;

		void position(Point);
		Point position() const;

		Size size() const;

		void add_x(int amount);
		void add_y(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing = 0);
		void place_below(const Box&, int spacing = 0);
		void place_on(const Box&);

	private:
		Point m_position;
		Size m_size;
	};
}
