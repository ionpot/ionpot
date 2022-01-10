#pragma once

#include <util/macros.hpp>

#include <string>

namespace ionpot::sdl {
	class Ttf {
	public:
		static bool was_init();
		static std::string version_str();

		Ttf();
		~Ttf();
		IONPOT_NO_COPY(Ttf)
	};
}
