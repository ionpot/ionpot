#pragma once

#include "event.hpp"

#include <util/macros.hpp>

#include <SDL.h>

#include <optional>

namespace ionpot::sdl {
	class Base {
	public:
		static bool was_init();

		Base();
		~Base();
		IONPOT_NO_COPY(Base)

		void delay(Uint32 milliseconds) const;
		std::optional<Event> poll_event() const;
	};
}
