#pragma once

#include "event.hpp"
#include "point.hpp"
#include "video.hpp"

#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Mouse {
	public:
		using LeftClick = Point;

		Mouse(std::shared_ptr<const Video>);

		bool lmb_down() const;

		std::optional<Point> moved() const;

		Point position() const;
		Point query_position() const;

		void update();
		void update(Point new_mouse_pos);
		std::optional<LeftClick> update(const Event&);

	private:
		std::shared_ptr<const Video> m_video;
		util::Value<Point> m_position;
		bool m_lmb_down;
	};
}
