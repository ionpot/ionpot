#pragma once

#include "events.hpp"
#include "point.hpp"

#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Mouse {
	public:
		Mouse(std::shared_ptr<Events>);

		Point position() const;
		std::optional<Point> moved() const;

		void update();
		void update(Point new_mouse_pos);

	private:
		std::shared_ptr<Events> m_events;
		util::Value<Point> m_position;
	};
}
