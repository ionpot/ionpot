#pragma once

#include "size.hpp"
#include "surface.hpp"
#include "ttf.hpp"

#include <util/macros.hpp>
#include <util/rgba.hpp>

#include <SDL_ttf.h>

#include <memory> // std::shared_ptr
#include <string>
#include <vector>

namespace ionpot::sdl {
	class Font {
	public:
		struct Config {
			std::string file;
			int height;
		};

		Font(std::shared_ptr<Ttf>, const Config&);
		~Font();
		IONPOT_NO_COPY(Font)
		IONPOT_DECLARE_MOVE(Font)

		Size calculate_size(std::string) const;

		int line_height() const;
		int line_skip() const;

		Size max_size(const std::vector<std::string>&) const;

		Surface render_blended(std::string text, const util::RGBA&) const;

	private:
		std::shared_ptr<Ttf> m_ttf;
		TTF_Font* m_font;
	};
}
