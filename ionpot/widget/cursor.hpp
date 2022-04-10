#pragma once

#include "box.hpp"
#include "point.hpp"

#include <sdl/mouse.hpp>

#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <vector>

namespace ionpot::widget {
	class Cursor {
	public:
		using Widget = std::shared_ptr<const Box>;
		using Widgets = std::vector<Widget>;

		Cursor(
			std::shared_ptr<sdl::Mouse>,
			Widgets&&);

		bool is_on(const Widget&) const;
		bool has_entered(const Widget&) const;
		bool has_left(const Widget&) const;

		Widget find(Point) const;

		void update();

	private:
		std::shared_ptr<sdl::Mouse> m_mouse;
		Widgets m_widgets;
		util::Value<Widget> m_hovered;
	};
}
