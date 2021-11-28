#pragma once

#include "point.hpp"

#include <util/size.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	struct Rect {
		Point position;
		util::Size size;
		Rect(util::Size);
		Rect(Point, util::Size);
		bool contains(Point) const;
		SDL_Rect to_sdl() const;
	};
}
