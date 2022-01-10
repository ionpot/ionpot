#pragma once

#include <SDL.h>

#include <string>

namespace ionpot::sdl::version {
	std::string as_string();
	SDL_version query();
	std::string to_string(const SDL_version&);
}
