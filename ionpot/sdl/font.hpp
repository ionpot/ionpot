#pragma once

#include "surface.hpp"

#include <util/macros.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <SDL_ttf.h>

#include <string>
#include <vector>

namespace ionpot::sdl {
	class Font {
	public:
		struct Config {
			std::string file;
			int height;
		};

		~Font();
		IONPOT_NO_COPY(Font)
		IONPOT_DECLARE_MOVE(Font)

		util::Size calculate_size(std::string) const;

		int line_height() const;
		int line_skip() const;

		util::Size max_size(const std::vector<std::string>&) const;

		Surface render_blended(std::string text, const util::RGBA&) const;

	private:
		friend struct Ttf;
		TTF_Font* m_font;
		Font(const Config&);
	};
}
