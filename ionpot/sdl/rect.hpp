#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	struct Rect {
		util::Point position;
		util::Size size;
		Rect(util::Size);
		Rect(util::Point, util::Size);
		bool contains(util::Point) const;
		SDL_Rect to_sdl() const;
	};
}
