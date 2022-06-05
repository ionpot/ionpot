#pragma once

#include "element.hpp"

#include <sdl/mouse.hpp>

#include <util/point.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::widget {
	class Mouse {
	public:
		Mouse(sdl::Mouse&&);

		std::shared_ptr<const Element> hovered() const;
		void hovered(std::shared_ptr<Element>);

		void lmb_down(std::shared_ptr<Element>);
		bool lmb_up(std::shared_ptr<Element>);

		std::optional<util::Point> moved();

		util::Point position() const;

	private:
		sdl::Mouse m_mouse;
		util::Point m_last_pos;
		std::shared_ptr<Element> m_hovered;
		std::shared_ptr<Element> m_click_start;
	};
}
