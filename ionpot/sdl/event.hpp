#pragma once

#include "key.hpp"
#include "point.hpp"

#include <SDL.h>
#include <optional>

namespace ionpot::sdl {
	class Event {
	public:
		Event(SDL_Event&&);

		bool focus_gained() const;
		bool focus_lost() const;
		std::optional<Key> key_down() const;
		std::optional<Key> key_up() const;
		std::optional<Point> lmb_down() const;
		std::optional<Point> lmb_up() const;
		std::optional<Point> mouse_move() const;
		bool quit() const;

	private:
		SDL_Event m_event;
	};
}
