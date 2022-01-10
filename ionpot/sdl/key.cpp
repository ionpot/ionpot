#include "key.hpp"

#include <SDL.h>
#include <string>

namespace ionpot::sdl {
	Key::Key(const SDL_KeyboardEvent& event):
		keycode {event.keysym.sym},
		scancode {event.keysym.scancode},
		repeat {event.repeat}
	{}

	std::string
	Key::keycode_str() const
	{ return SDL_GetKeyName(keycode); }

	std::string
	Key::scancode_str() const
	{ return SDL_GetScancodeName(scancode); }
}
