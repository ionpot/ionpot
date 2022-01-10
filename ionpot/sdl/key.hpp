#pragma once

#include <SDL.h>
#include <string>

namespace ionpot::sdl {
	struct Key {
		SDL_Keycode keycode;
		SDL_Scancode scancode;
		int repeat;

		Key(const SDL_KeyboardEvent&);

		std::string keycode_str() const;
		std::string scancode_str() const;
	};
}
