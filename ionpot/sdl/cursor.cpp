#include "cursor.hpp"

#include "exception.hpp"

#include <SDL.h>

namespace ionpot::sdl {
	Cursor::Cursor(SDL_SystemCursor id):
		m_cursor {SDL_CreateSystemCursor(id)}
	{
		if (!m_cursor) {
			throw Exception {};
		}
	}

	Cursor::~Cursor()
	{
		if (m_cursor) {
			SDL_FreeCursor(m_cursor);
		}
	}

	Cursor::Cursor(Cursor&& from) noexcept:
		m_cursor {from.m_cursor}
	{
		from.m_cursor = NULL;
	}

	Cursor&
	Cursor::operator=(Cursor&& from) noexcept
	{
		m_cursor = from.m_cursor;
		from.m_cursor = NULL;
		return *this;
	}

	void
	Cursor::set() const
	{
		SDL_SetCursor(m_cursor);
	}
}
