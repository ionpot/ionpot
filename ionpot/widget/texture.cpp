#include "texture.hpp"

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/font.hpp>
#include <sdl/renderer.hpp>
#include <sdl/texture.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <string>
#include <utility> // std::move

namespace ionpot::widget {
	Texture::Texture(sdl::Texture&& tx, Size size):
		Box {size},
		m_texture {std::move(tx)}
	{}

	Texture::Texture(sdl::Texture&& tx):
		Texture(std::move(tx), tx.query_size())
	{}

	Texture::Texture(
			std::shared_ptr<sdl::Renderer> renderer,
			const sdl::Font& font,
			const util::RGBA& color,
			std::string text
	):
		Texture(
			sdl::Texture {
				renderer,
				font.render_blended(text, color)
			},
			font.calculate_size(text)
		)
	{}

	void
	Texture::render(Point offset) const
	{
		m_texture.render(position() + offset, size());
	}
}
