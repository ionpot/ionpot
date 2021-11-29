#pragma once

#include "font.hpp"

#include <util/log.hpp>
#include <util/macros.hpp>

namespace ionpot::sdl {
	struct Ttf {
		static bool was_init();

		Ttf(util::Log& log);
		~Ttf();
		IONPOT_NO_COPY(Ttf)

		Font load_font(const Font::Config&, util::Log&) const;
	};
}
