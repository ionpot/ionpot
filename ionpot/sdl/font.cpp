#include "font.hpp"

#include "color.hpp"
#include "size.hpp"
#include "surface.hpp"
#include "ttf.hpp"
#include "ttf_exception.hpp"

#include <util/rgba.hpp>

#include <SDL_ttf.h>

#include <memory> // std::shared_ptr
#include <string>
#include <vector>

namespace ionpot::sdl {
	Font::Font(
			std::shared_ptr<const Ttf> ttf,
			const Config& config):
		m_ttf {ttf},
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
		m_ttf {from.m_ttf},
		m_font {from.m_font}
	{
		from.m_font = NULL;
	}

	Font&
	Font::operator=(Font&& from) noexcept
	{
		m_ttf = from.m_ttf;
		m_font = from.m_font;
		from.m_font = NULL;
		return *this;
	}

	Size
	Font::calculate_size(std::string text) const
	{
		int width {0};
		int height {0};
		if (TTF_SizeUTF8(m_font, text.c_str(), &width, &height))
			throw TtfException {};
		return {width, height};
	}

	bool
	Font::is_bold() const
	{
		return TTF_GetFontStyle(m_font) & TTF_STYLE_BOLD;
	}

	bool
	Font::is_normal() const
	{
		return TTF_GetFontStyle(m_font) == TTF_STYLE_NORMAL;
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

	Size
	Font::max_size(const std::vector<std::string>& ls) const
	{
		Size output {0};
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

	void
	Font::set_bold() const
	{
		if (!is_bold())
			TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);
	}

	void
	Font::set_normal() const
	{
		if (!is_normal())
			TTF_SetFontStyle(m_font, TTF_STYLE_NORMAL);
	}
}
