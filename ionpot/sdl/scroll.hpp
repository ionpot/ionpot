#pragma once

#include "point.hpp"

#include <util/size.hpp>

#include <string>

namespace ionpot::sdl {
	class Scroll {
	public:
		Scroll(util::Size screen, util::Size content, int speed);
		Point next(Point) const;
		void start_left();
		void start_right();
		void start_up();
		void start_down();
		void stop();
		void stop_left();
		void stop_right();
		void stop_up();
		void stop_down();
		std::string to_str() const;

	private:
		Point m_max;
		int m_speed;
		Point m_state;
	};
}
