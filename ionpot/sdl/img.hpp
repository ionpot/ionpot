#pragma once

#include "rwops.hpp"
#include "surface.hpp"

#include <util/macros.hpp>

#include <string>

namespace ionpot::sdl {
	struct Img {
		using Flags = int;

		static const Flags default_flags;
		static bool was_init;

		static std::string version_str();

		Img(Flags = default_flags);
		~Img();
		IONPOT_NO_COPY(Img)

		Surface load_png(const RWops&) const;
	};
}
