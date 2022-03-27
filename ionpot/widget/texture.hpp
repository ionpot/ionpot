#pragma once

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/texture.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	class Texture : public Box {
	public:
		Texture(sdl::Texture&& tx, Size size):
			Box {size},
			m_texture {std::move(tx)}
		{}

		Texture(sdl::Texture&& tx):
			Texture(std::move(tx), tx.query_size())
		{}

		void render(Point offset = {0}) const
		{ m_texture.render(position() + offset, size()); }

	private:
		sdl::Texture m_texture;
	};
}
