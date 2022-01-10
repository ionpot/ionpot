#pragma once

#include <util/macros.hpp>

#include <SDL.h>

namespace ionpot::sdl {
	class Base {
	public:
		static bool was_init();

		Base();
		~Base();
		IONPOT_NO_COPY(Base)

		void delay(Uint32 milliseconds) const;
	};
}
