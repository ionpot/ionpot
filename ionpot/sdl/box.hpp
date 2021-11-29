#pragma once

#include "renderer.hpp"
#include "texture.hpp"

#include <util/point.hpp>
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

		util::Point content(util::Point offset) const;

		void render(const Renderer&, util::Point position) const;

	private:
		util::Point m_content;
		TargetTexture m_texture;
	};
}
