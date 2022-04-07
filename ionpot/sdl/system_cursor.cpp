#include "system_cursor.hpp"

#include "cursor.hpp"

#include <SDL.h>

namespace ionpot::sdl {
	SystemCursor::Arrow::Arrow():
		Cursor {SDL_SYSTEM_CURSOR_ARROW}
	{}
	SystemCursor::Hand::Hand():
		Cursor {SDL_SYSTEM_CURSOR_HAND}
	{}
}
