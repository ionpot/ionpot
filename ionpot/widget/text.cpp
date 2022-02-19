#include "text.hpp"

#include "point.hpp"
#include "size.hpp"

#include <sdl/texture.hpp>

#include <string>

namespace ionpot::widget {
	Text::Text(const Config& config, std::string text):
		m_texture {
			sdl::SizedTexture {
				sdl::Texture {
					config.renderer,
					config.font->render_blended(text, config.color)
				}
			}
		},
		m_size {
			m_texture.size().width,
			config.font->line_height()
		}
	{}

	void
	Text::render(Point offset) const
	{ m_texture.render(m_position + offset); }

	Size
	Text::size() const
	{ return m_size; }
}
