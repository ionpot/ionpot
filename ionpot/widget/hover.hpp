#pragma once

#include "box.hpp"
#include "point.hpp"

#include <sdl/mouse.hpp>

#include <util/value.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class Hover {
	public:
		Hover(std::shared_ptr<const sdl::Mouse>);

		bool is_hovered() const;
		bool has_entered() const;
		bool has_left() const;

		void update(const Box&, Point offset = {});

	private:
		std::shared_ptr<const sdl::Mouse> m_mouse;
		util::Value<bool> m_hovered;
	};
}
