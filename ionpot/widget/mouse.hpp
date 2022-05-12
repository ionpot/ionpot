#pragma once

#include "element.hpp"

#include <sdl/mouse.hpp>

#include <util/point.hpp>

#include <optional>

namespace ionpot::widget {
	class Mouse {
	public:
		Mouse(sdl::Mouse&&);

		const Element* hovered() const;
		void hovered(Element*);

		void lmb_down(Element*);
		bool lmb_up(Element*);

		std::optional<util::Point> moved();

		util::Point position() const;

	private:
		sdl::Mouse m_mouse;
		util::Point m_last_pos;
		Element* m_hovered;
		Element* m_click_start;
	};
}
