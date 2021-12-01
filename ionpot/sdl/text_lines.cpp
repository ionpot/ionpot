#include "text_lines.hpp"

#include "font.hpp"
#include "renderer.hpp"
#include "text.hpp"

#include <util/int.hpp>
#include <util/point.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <string>
#include <utility> // std::move
#include <vector>

namespace ionpot::sdl {
	namespace {
		std::vector<Text>
		s_lines(
				const Font& font,
				const Renderer& rdr,
				const std::vector<std::string>& lines,
				const util::RGBA& text_color)
		{
			std::vector<Text> vector;
			vector.reserve(lines.size());
			for (auto line : lines)
				vector.emplace_back(font, rdr, line, text_color);
			return vector;
		}
	}

	TextLines::TextLines(
			int lskip,
			std::vector<Text>&& lns
	):
		m_lines {std::move(lns)},
		m_line_skip {lskip},
		m_size {}
	{
		auto& [width, height] = m_size;
		for (const auto& line : m_lines) {
			if (auto w = line.width(); w > width)
				width = w;
		}
		if (auto sz = m_lines.size()) {
			auto h = m_lines.front().height();
			height = h + m_line_skip * IONPOT_INT(--sz);
		}
	}

	TextLines::TextLines(
			const Font& font,
			std::vector<Text>&& lines
	):
		TextLines {font.line_skip(), std::move(lines)}
	{}

	TextLines::TextLines(
			const Font& font,
			const Renderer& rdr,
			const std::vector<std::string>& lines,
			const util::RGBA& text_color
	):
		TextLines {font, s_lines(font, rdr, lines, text_color)}
	{}

	void
	TextLines::render(const Renderer& rdr, util::Point position) const
	{
		for (const auto& line : m_lines) {
			line.render(rdr, position);
			position.y += m_line_skip;
		}
	}

	util::Size
	TextLines::size() const
	{
		return m_size;
	}
}
