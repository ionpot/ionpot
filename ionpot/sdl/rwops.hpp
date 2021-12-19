#pragma once

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	class RWops {
		friend class Base;

	public:
		SDL_RWops* pointer;

		~RWops();
		IONPOT_NO_COPY(RWops)
		IONPOT_DECLARE_MOVE(RWops)

	private:
		RWops(SDL_RWops*);
	};
}
