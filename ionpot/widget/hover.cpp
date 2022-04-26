#include "hover.hpp"

#include "box.hpp"

#include <sdl/mouse.hpp>

#include <util/point.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	Hover::Hover(std::shared_ptr<const sdl::Mouse> mouse):
		m_mouse {mouse},
		m_hovered {false}
	{}

	bool
	Hover::is_hovered() const
	{
		return m_hovered.current();
	}

	bool
	Hover::has_entered() const
	{
		return m_hovered.changed()
			&& is_hovered();
	}

	bool
	Hover::has_left() const
	{
		return m_hovered.changed()
			&& m_hovered.previous();
	}

	void
	Hover::update(const Box& widget, util::Point offset)
	{
		if (auto pos = m_mouse->moved()) {
			m_hovered = widget.contains(*pos, offset);
		}
		else {
			m_hovered.set_to_same();
		}
	}
}
