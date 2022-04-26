#pragma once

#include <sdl/renderer.hpp>

#include <util/rgba.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	class Border {
	public:
		Border(int width, util::RGBA);

		void draw(const sdl::Renderer&, util::Size) const;

	private:
		int m_width;
		util::RGBA m_color;
	};
}
