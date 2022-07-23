#include "element.hpp"

#include "box.hpp"
#include "exception.hpp"
#include "sum_sizes.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	Element::Element(util::Size size,  util::Point pos):
		Box {size, pos},
		m_clickable {false},
		m_held_down {false},
		m_hovered {false},
		m_visible {true}
	{}

	Element::Children&
	Element::children()
	{ return m_children; }

	void
	Element::children(Children&& ls)
	{ m_children = std::move(ls); }

	Element::Child
	Element::find(util::Point p, util::Point offset)
	{
		if (hidden())
			return {};
		offset += position();
		for (auto child : m_children) {
			if (child->hidden())
				continue;
			if (auto found = child->find(p, offset))
				return found;
			if (child->contains(p, offset))
				return child;
		}
		return {};
	}

	void
	Element::render(util::Point offset) const
	{
		offset += position();
		for (const auto& child : m_children)
			child->render_if_visible(offset);
	}

	void
	Element::render_if_visible(util::Point offset) const
	{ if (m_visible) render(offset); }

	void
	Element::swap_child(Child& old, Child nw)
	{
		for (auto& child : m_children) {
			if (child == old) {
				nw->place_on(*old);
				child = old = nw;
				return;
			}
		}
		throw Exception {"Unknown child."};
	}

	void
	Element::update_size()
	{ size(sum_sizes(m_children)); }

	bool
	Element::clickable() const
	{ return m_clickable; }

	void
	Element::clickable(bool value)
	{ m_clickable = value; }

	bool
	Element::held_down() const
	{ return m_held_down; }

	void
	Element::held_down(bool value)
	{ m_held_down = value; }

	bool
	Element::hidden() const
	{ return !m_visible; }

	void
	Element::hidden(bool value)
	{ m_visible = !value; }

	bool
	Element::hovered() const
	{ return m_hovered; }

	void
	Element::hovered(bool value)
	{ m_hovered = value; }

	bool
	Element::visible() const
	{ return m_visible; }

	void
	Element::visible(bool value)
	{ m_visible = value; }

	void
	Element::show()
	{ m_visible = true; }

	void
	Element::hide()
	{ m_visible = false; }

	bool
	Element::operator==(const Element& e) const
	{ return this == &e; }

	bool
	Element::operator!=(const Element& e) const
	{ return this != &e; }
}
