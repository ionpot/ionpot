#pragma once

#include "video.hpp"

#include <util/point.hpp>
#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Mouse {
	public:
		Mouse(std::shared_ptr<const Video>);

		std::optional<util::Point> moved() const;

		util::Point position() const;
		util::Point query_position() const;

		void update();
		void update(util::Point new_mouse_pos);

	private:
		std::shared_ptr<const Video> m_video;
		util::Value<util::Point> m_position;
	};
}
