#include "base.hpp"

#include "exception.hpp"
#include "event.hpp"

#include <SDL.h>

#include <optional>

namespace ionpot::sdl {
	bool
	Base::was_init()
	{
		return SDL_WasInit(0) > 0;
	}

	Base::Base()
	{
		if (was_init())
			throw Exception {"Cannot re-initialize."};

		if (SDL_Init(0)) {
			Exception ex; // <-- uses SDL_GetError
			SDL_Quit();
			throw ex;
		}
	}

	Base::~Base()
	{
		SDL_Quit();
	}

	void
	Base::delay(Uint32 milliseconds) const
	{
		SDL_Delay(milliseconds);
	}

	std::optional<Event>
	Base::poll_event() const
	{
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			return {Event {event}};
		}
		return {};
	}
}
