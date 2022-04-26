#include "texture.hpp"

#include "box.hpp"

#include <sdl/texture.hpp>

#include <util/point.hpp>
#include <util/size.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	Texture::Texture(sdl::Texture&& tx, util::Size size):
		Box {size},
		m_texture {std::move(tx)}
	{}

	Texture::Texture(sdl::Texture&& tx):
		Texture(std::move(tx), tx.query_size())
	{}

	void
	Texture::render(util::Point offset) const
	{
		m_texture.render(position() + offset, size());
	}
}
