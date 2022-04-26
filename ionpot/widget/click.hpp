#pragma once

#include "box.hpp"

#include <sdl/event.hpp>

#include <util/point.hpp>

#include <optional>

namespace ionpot::widget {
	class Click {
	public:
		Click(util::Point start, util::Point end);

		bool on(const Box&, util::Point offset = {}) const;

	private:
		util::Point m_start;
		util::Point m_end;
	};

	class LeftClick {
	public:
		LeftClick();

		std::optional<Click> check(const sdl::Event&);
		bool pressed_on(const Box&, util::Point offset = {}) const;

	private:
		std::optional<util::Point> m_down;
	};
}
