#include "events.hpp"

#include "base.hpp"
#include "exception.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr
#include <optional>
#include <utility> // std::move

namespace ionpot::sdl {
	Events::Events(std::shared_ptr<const Base> base):
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
