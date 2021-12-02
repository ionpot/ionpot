#include "box.hpp"

#include "renderer.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::sdl {
	Box::Box(
			const Box::Config& config,
			const Renderer& rdr,
			util::Size inner_size
	):
		Box(config, rdr, inner_size, inner_size)
	{}

	Box::Box(
			const Box::Config& config,
			const Renderer& rdr,
			util::Size inner_size,
			util::Size content_size
	):
		m_content {util::Size {config.border_width} + config.padding},
		m_texture {rdr.create_target_texture(
			inner_size + util::Size {m_content * 2}
		)}
	{
		m_content += inner_size.center(content_size);
		rdr.set_target(m_texture);
		rdr.set_color(config.background_color);
		rdr.clear();
		rdr.set_color(config.border_color);
		util::Point offset;
		auto size = m_texture.size;
		for (auto i = config.border_width; i > 0; --i) {
			rdr.draw_rect({offset++, size});
			size -= 2;
		}
		rdr.reset_target();
	}

	util::Point
	Box::content(util::Point offset) const
	{
		return offset + m_content;
	}

	void
	Box::render(const Renderer& rdr, util::Point pos) const
	{
		rdr.put(m_texture, pos);
	}
}
