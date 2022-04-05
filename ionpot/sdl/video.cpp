#include "video.hpp"

#include "base.hpp"
#include "exception.hpp"
#include "point.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	Video::Video(std::shared_ptr<const Base> base):
		m_base {base}
	{
		if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {
			throw Exception {};
		}
	}

	Video::~Video()
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

	Point
	Video::mouse_position() const
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return {x, y};
	}
}
