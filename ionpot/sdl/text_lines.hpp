#pragma once

#include "font.hpp"
#include "point.hpp"
#include "renderer.hpp"
#include "text.hpp"

#include <util/rgba.hpp>
#include <util/size.hpp>

#include <string>
#include <vector>

namespace ionpot::sdl {
	class TextLines {
	public:
		TextLines(int line_skip, std::vector<Text>&& lines);
		TextLines(const Font&, std::vector<Text>&& lines);
		TextLines(
			const Font&,
			const Renderer&,
			const std::vector<std::string>& lines,
			const util::RGBA& text_color);

		void render(const Renderer&, Point position) const;

		util::Size size() const;

	private:
		std::vector<Text> m_lines;
		int m_line_skip;
		util::Size m_size;
	};
}
