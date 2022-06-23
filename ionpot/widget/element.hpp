#pragma once

#include "box.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <memory> // std::shared_ptr
#include <vector>

namespace ionpot::widget {
	class Element : public Box {
	public:
		using Child = std::shared_ptr<Element>;
		using Children = std::vector<Child>;

		Element(util::Size = {}, util::Point = {});
		virtual ~Element() {}

		Child find(util::Point, util::Point offset = {});

		virtual void render(util::Point = {}) const;

		void render_if_visible(util::Point offset = {}) const;

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

	protected:
		Children& children();
		void children(Children&&);

		void update_size();

	private:
		Children m_children;
		bool m_clickable;
		bool m_held_down;
		bool m_hovered;
		bool m_visible;
	};
}
