#include "cursor.hpp"

#include "point.hpp"

#include <sdl/mouse.hpp>

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	Cursor::Cursor(
			std::shared_ptr<sdl::Mouse> mouse,
			Widgets&& widgets
	):
		m_mouse {mouse},
		m_widgets {std::move(widgets)},
		m_hovered {}
	{}

	Cursor::Widget
	Cursor::find(Point p) const
	{
		if (auto widget = m_hovered.current()) {
			if (widget->contains(p)) {
				return widget;
			}
		}
		for (auto widget : m_widgets) {
			if (widget->contains(p)) {
				return widget;
			}
		}
		return nullptr;
	}

	bool
	Cursor::is_on(const Widget& widget) const
	{
		return m_hovered.current() == widget;
	}

	bool
	Cursor::has_entered(const Widget& widget) const
	{
		return m_hovered.changed() == widget;
	}

	bool
	Cursor::has_left(const Widget& widget) const
	{
		return m_hovered.changed()
			&& (m_hovered.previous() == widget);
	}

	void
	Cursor::update()
	{
		if (auto pos = m_mouse->moved()) {
			m_hovered = find(*pos);
		}
		else {
			m_hovered.set_to_same();
		}
	}
}
