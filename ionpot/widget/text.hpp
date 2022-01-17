#pragma once

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/font.hpp>
#include <sdl/renderer.hpp>
#include <sdl/texture.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::widget {
	class Text : public Box {
	public:
		struct Config {
			std::shared_ptr<sdl::Renderer> renderer;
			std::shared_ptr<sdl::Font> font;
			util::RGBA color;
		};

		Text(const Config&, std::string text);

		void position(Point p) override;
		Point position() const override;

		void render(Point offset = {0}) const;

		Size size() const override;

	private:
		sdl::SizedTexture m_texture;
		Size m_size;
		Point m_position;
	};
}
