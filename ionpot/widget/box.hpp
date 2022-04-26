#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	class Box {
	public:
		Box(util::Size, util::Point pos = {});

		bool contains(util::Point, util::Point offset = {}) const;

		util::Point max_point() const;

		void position(util::Point);
		util::Point position() const;

		util::Size size() const;

		void add_x(int amount);
		void add_y(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing = 0);
		void place_below(const Box&, int spacing = 0);
		void place_on(const Box&);

	private:
		util::Point m_position;
		util::Size m_size;
	};
}
