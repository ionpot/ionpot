#include "click.hpp"

#include "box.hpp"
#include "point.hpp"

#include <sdl/event.hpp>

#include <optional>

namespace ionpot::widget {
	Click::Click(Point start, Point end):
		m_start {start},
		m_end {end}
	{}

	bool
	Click::on(const Box& widget, Point offset) const
	{
		return widget.contains(m_start, offset)
			&& widget.contains(m_end, offset);
	}

	// left click
	LeftClick::LeftClick():
		m_down {}
	{}

	std::optional<Click>
	LeftClick::check(const sdl::Event& event)
	{
		if (event.focus_lost()) {
			m_down.reset();
		}
		else if (auto pos = event.lmb_down()) {
			m_down = pos;
		}
		else if (auto up = event.lmb_up()) {
			if (m_down) {
				auto down = *m_down;
				m_down.reset();
				return Click {down, *up};
			}
		}
		return {};
	}

	bool
	LeftClick::pressed_on(const Box& widget, Point offset) const
	{
		return m_down && widget.contains(*m_down, offset);
	}
}
