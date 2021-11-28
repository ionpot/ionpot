#pragma once

#include "point.hpp"
#include "renderer.hpp"
#include "texture.hpp"

#include <util/rgb.hpp>
#include <util/size.hpp>

namespace ionpot::sdl {
	class Box {
	public:
		struct Config {
			util::RGB background_color;
			util::RGB border_color;
			int border_width;
			util::Size padding;
		};

		Box(const Config&, const Renderer&, util::Size inner_size);

		Point content(Point offset) const;

		void render(const Renderer&, Point position) const;

	private:
		Point m_content;
		TargetTexture m_texture;
	};
}
