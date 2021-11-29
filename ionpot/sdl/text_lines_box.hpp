#pragma once

#include "box.hpp"
#include "font.hpp"
#include "renderer.hpp"
#include "text_box.hpp"
#include "text_lines.hpp"

#include <util/point.hpp>

#include <string>
#include <vector>

namespace ionpot::sdl {
	class TextLinesBox {
	public:
		TextLinesBox(
			const Box::Config&,
			const Renderer&,
			TextLines&& content);

		TextLinesBox(
			const TextBox::Config&,
			const Font&,
			const Renderer&,
			const std::vector<std::string>& lines);

		void render(const Renderer&, util::Point position) const;

	private:
		TextLines m_lines;
		Box m_box;
	};
}
