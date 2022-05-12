#pragma once

#include "video.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Mouse {
	public:
		Mouse(std::shared_ptr<const Video>);

		util::Point query_position() const;

	private:
		std::shared_ptr<const Video> m_video;
	};
}
