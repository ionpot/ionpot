#pragma once

#include <util/exception.hpp>

#include <SDL.h>
#include <string>

namespace ionpot::sdl {
	struct Exception : public util::Exception {
		Exception(std::string text):
			util::Exception {"SDL", text}
		{}
		Exception():
			Exception {SDL_GetError()}
		{}
	};
}
