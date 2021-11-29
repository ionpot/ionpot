#pragma once

#include "box.hpp"
#include "font.hpp"
#include "renderer.hpp"
#include "text.hpp"

#include <util/point.hpp>
#include <util/rgb.hpp>

#include <string>

namespace ionpot::sdl {
	class TextBox {
	public:
		struct Config {
			Box::Config box;
			util::RGB text_color;
		};

		TextBox(
			const TextBox::Config&,
			const Renderer&,
			Text&& content);

		TextBox(
			const TextBox::Config&,
			const Font&,
			const Renderer&,
			std::string content);

		void render(const Renderer&, util::Point position) const;

	private:
		Text m_text;
		Box m_box;
	};
}
