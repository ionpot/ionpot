#pragma once

#include "size.hpp"

#include <sdl/renderer.hpp>

#include <util/rgba.hpp>

namespace ionpot::widget {
	class Border {
	public:
		Border(int width, util::RGBA);

		void draw(const sdl::Renderer&, Size) const;

	private:
		int m_width;
		util::RGBA m_color;
	};
}
