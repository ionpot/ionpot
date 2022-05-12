#include "mouse.hpp"

#include "video.hpp"

#include <util/point.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	Mouse::Mouse(std::shared_ptr<const Video> video):
		m_video {video}
	{}

	util::Point
	Mouse::query_position() const
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return {x, y};
	}
}
