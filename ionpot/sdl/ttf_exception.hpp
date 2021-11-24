#pragma once

#include <util/exception.hpp>

#include <SDL_ttf.h>

#include <string>

namespace ionpot::sdl {
	struct TtfException : public util::Exception {
		TtfException(std::string text):
			util::Exception {"TTF", text}
		{}
		TtfException():
			TtfException {TTF_GetError()}
		{}
	};
}
