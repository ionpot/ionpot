#pragma once

#include "surface.hpp"
#include "ttf.hpp"

#include <util/macros.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

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

		Font(std::shared_ptr<const Ttf>, const Config&);
		~Font();
		IONPOT_NO_COPY(Font)
		IONPOT_DECLARE_MOVE(Font)

		util::Size calculate_size(std::string) const;

		bool is_normal() const;
		void set_normal() const;

		bool is_bold() const;
		void set_bold() const;

		int line_height() const;
		int line_skip() const;

		util::Size max_size(const std::vector<std::string>&) const;

		Surface render_blended(std::string text, const util::RGBA&) const;

	private:
		std::shared_ptr<const Ttf> m_ttf;
		TTF_Font* m_font;
	};
}
