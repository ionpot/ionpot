#pragma once

#include "point.hpp"
#include "video.hpp"

#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Mouse {
	public:
		Mouse(std::shared_ptr<Video>);

		Point position() const;
		std::optional<Point> moved() const;

		void update();
		void update(Point new_mouse_pos);

	private:
		std::shared_ptr<Video> m_video;
		util::Value<Point> m_position;
	};
}
