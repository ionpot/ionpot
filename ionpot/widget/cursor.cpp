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
			update(*pos);
		}
		else {
			m_hovered.set_to_same();
		}
	}

	void
	Cursor::update(Point p)
	{
		if (auto w = m_hovered.current()) {
			if (w->contains(p)) {
				m_hovered = w;
				return;
			}
		}
		Widget new_widget {};
		for (const auto& widget : m_widgets) {
			if (widget->contains(p)) {
				new_widget = widget;
				break;
			}
		}
		m_hovered = new_widget;
	}
}
