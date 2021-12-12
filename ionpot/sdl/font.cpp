#include "font.hpp"

#include "color.hpp"
#include "surface.hpp"
#include "ttf_exception.hpp"

#include <util/rgba.hpp>
#include <util/size.hpp>

#include <SDL_ttf.h>

#include <string>
#include <vector>

namespace ionpot::sdl {
	Font::Font(const Config& config):
		m_font {TTF_OpenFont(config.file.c_str(), config.height)}
	{
		if (!m_font)
			throw TtfException {};
	}

	Font::~Font()
	{
		if (m_font) {
			TTF_CloseFont(m_font);
			m_font = NULL;
		}
	}

	Font::Font(Font&& from) noexcept:
		m_font {from.m_font}
	{
		from.m_font = NULL;
	}

	Font&
	Font::operator=(Font&& from) noexcept
	{
		m_font = from.m_font;
		from.m_font = NULL;
		return *this;
	}

	util::Size
	Font::calculate_size(std::string text) const
	{
		int w {0};
		int h {0};
		if (TTF_SizeUTF8(m_font, text.c_str(), &w, &h))
			throw TtfException {};
		return {w, h};
	}

	int
	Font::line_height() const
	{
		return TTF_FontHeight(m_font);
	}

	int
	Font::line_skip() const
	{
		return TTF_FontLineSkip(m_font);
	}

	util::Size
	Font::max_size(const std::vector<std::string>& ls) const
	{
		util::Size output {0};
		for (auto text : ls) {
			auto size = calculate_size(text);
			output.pick_max(size);
		}
		return output;
	}

	Surface
	Font::render_blended(std::string text, const util::RGBA& color) const
	{
		Surface surface {
			TTF_RenderUTF8_Blended(m_font, text.c_str(), color_rgba(color))
		};
		if (!surface.pointer)
			throw TtfException {};
		return surface;
	}
}
