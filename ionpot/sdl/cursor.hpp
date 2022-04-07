#pragma once

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	class Cursor {
	public:
		Cursor(SDL_SystemCursor);
		~Cursor();
		IONPOT_NO_COPY(Cursor)
		IONPOT_DECLARE_MOVE(Cursor)

		void set() const;

	private:
		SDL_Cursor* m_cursor;
	};
}
