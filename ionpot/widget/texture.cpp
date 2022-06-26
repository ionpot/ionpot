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
	{}

	Texture::Texture(sdl::Texture&& tx):
		Texture(std::move(tx), tx.query_size())
	{}

	void
	Texture::alpha(sdl::Texture::Alpha value) const
	{ m_texture.set_alpha(value); }

	void
	Texture::render(util::Point offset) const
	{ m_texture.render(position() + offset, size()); }
}
