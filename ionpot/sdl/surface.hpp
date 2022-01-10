#pragma once

#include "video.hpp"

#include <util/macros.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Surface {
	public:
		SDL_Surface* pointer;

		Surface(std::shared_ptr<Video>, SDL_Surface*);
		~Surface();
		IONPOT_NO_COPY(Surface)
		IONPOT_DECLARE_MOVE(Surface)

	private:
		std::shared_ptr<Video> m_video;
	};
}
