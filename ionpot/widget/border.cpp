#include "border.hpp"

#include <sdl/renderer.hpp>

#include <util/point.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	Border::Border(int width, util::RGBA color):
		m_width {width},
		m_color {color}
	{}

	void
	Border::draw(const sdl::Renderer& rdr, util::Size size) const
	{
		rdr.set_color(m_color);
		util::Point offset;
		for (auto i = m_width; i > 0; --i) {
			rdr.draw_rect(offset++, size);
			size -= 2;
		}
	}
}
