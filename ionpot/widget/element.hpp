#pragma once

#include "box.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	class Element;

	template<class T> // T = Element
	bool
	contains(const T& elmt, util::Point point, util::Point offset = {})
	{
		return elmt.visible()
			&& elmt.contains(point, offset);
	}

	template<class T> // T = Element
	Element*
	find(T& elmt, util::Point point, util::Point offset = {})
	{
		return elmt.visible()
			? elmt.find(point, offset)
			: nullptr;
	}

	template<class T> // T = Element
	void
	render(const T& elmt, util::Point offset = {})
	{
		if (elmt.visible())
			elmt.render(offset);
	}

	class Element : public Box {
	public:
		Element(util::Size = {}, util::Point = {});

		bool clickable() const;
		void clickable(bool);

		bool held_down() const;
		void held_down(bool);

		bool hovered() const;
		void hovered(bool);

		bool visible() const;
		void visible(bool);

		bool hidden() const;
		void hidden(bool);

		void show();
		void hide();

		bool operator==(const Element& e) const;
		bool operator!=(const Element& e) const;

		using Box::contains;

		template<class T> // T = Element
		bool
		contains(const T& elmt, util::Point point, util::Point offset = {})
		{ return widget::contains(elmt, point, position() + offset); }

		template<class T> // T = Element
		Element*
		find(T& elmt, util::Point point, util::Point offset = {})
		{ return widget::find(elmt, point, position() + offset); }

		template<class T> // T = Element
		void
		render(const T& elmt, util::Point offset = {}) const
		{ widget::render(elmt, position() + offset); }

	private:
		bool m_clickable;
		bool m_held_down;
		bool m_hovered;
		bool m_visible;
	};
}
