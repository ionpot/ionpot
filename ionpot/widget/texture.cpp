#include "texture.hpp"

#include "element.hpp"

#include <sdl/texture.hpp>

#include <util/point.hpp>
#include <util/size.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	Texture::Texture(sdl::Texture&& tx, util::Size size):
		Element {size},
		m_texture {std::move(tx)}
	{ m_texture.set_blend(); }

	Texture::Texture(sdl::Texture&& tx):
		Texture(std::move(tx), tx.query_size())
	{}

	void
	Texture::alpha(sdl::Texture::Alpha value) const
	{ m_texture.set_alpha(value); }

	void
	Texture::half_transparent() const
	{ m_texture.half_transparent(); }

	void
	Texture::opaque() const
	{ m_texture.opaque(); }

	void
	Texture::render(util::Point offset) const
	{ m_texture.render(position() + offset, size()); }
}
