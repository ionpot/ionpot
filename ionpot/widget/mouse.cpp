#include "mouse.hpp"

#include "element.hpp"

#include <sdl/mouse.hpp>

#include <util/point.hpp>

#include <memory> // std::shared_ptr
#include <optional>
#include <utility> // std::move

namespace ionpot::widget {
	Mouse::Mouse(sdl::Mouse&& mouse):
		m_mouse {std::move(mouse)},
		m_last_pos {},
		m_hovered {},
		m_click_start {}
	{}

	std::shared_ptr<const Element>
	Mouse::hovered() const
	{ return m_hovered; }

	void
	Mouse::hovered(std::shared_ptr<Element> elmt)
	{
		if (m_click_start)
			m_click_start->held_down(m_click_start == elmt);
		if (m_hovered)
			m_hovered->hovered(false);
		if (elmt)
			elmt->hovered(true);
		m_hovered = elmt;
	}

	void
	Mouse::lmb_down(std::shared_ptr<Element> elmt)
	{
		if (m_click_start)
			m_click_start->held_down(false);
		if (elmt)
			elmt->held_down(true);
		m_click_start = elmt;
	}

	bool
	Mouse::lmb_up(std::shared_ptr<Element> elmt)
	{
		bool clicked {false};
		if (m_click_start) {
			m_click_start->held_down(false);
			clicked = (m_click_start == elmt);
			if (elmt)
				clicked &= elmt->clickable();
		}
		m_click_start.reset();
		return clicked;
	}

	std::optional<util::Point>
	Mouse::moved()
	{
		auto pos = m_mouse.query_position();
		if (pos != m_last_pos) {
			m_last_pos = pos;
			return pos;
		}
		return {};
	}

	util::Point
	Mouse::position() const
	{ return m_last_pos; }
}
