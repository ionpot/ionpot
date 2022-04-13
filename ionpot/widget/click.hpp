#pragma once

#include "box.hpp"
#include "point.hpp"

#include <sdl/event.hpp>

#include <optional>

namespace ionpot::widget {
	class Click {
	public:
		Click(Point start, Point end);

		bool on(const Box&, Point offset = {0}) const;

	private:
		Point m_start;
		Point m_end;
	};

	class LeftClick {
	public:
		LeftClick();

		std::optional<Click> check(const sdl::Event&);
		bool pressed_on(const Box&, Point offset = {0}) const;

	private:
		std::optional<Point> m_down;
	};
}
