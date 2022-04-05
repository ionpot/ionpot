#include "events.hpp"

#include "base.hpp"
#include "exception.hpp"
#include "point.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr
#include <optional>
#include <utility> // std::move

namespace ionpot::sdl {
	Events::Events(std::shared_ptr<Base> base):
		m_base {base}
	{
		if (SDL_InitSubSystem(SDL_INIT_EVENTS)) {
			throw Exception {};
		}
	}

	Events::~Events()
	{
		SDL_QuitSubSystem(SDL_INIT_EVENTS);
	}

	Point
	Events::mouse_position() const
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return {x, y};
	}

	std::optional<Event>
	Events::poll() const
	{
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			return {Event {std::move(event)}};
		}
		return {};
	}
}
