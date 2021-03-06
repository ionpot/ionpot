#pragma once

#include "element.hpp"

#include <sdl/texture.hpp>

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	class Texture : public Element {
	public:
		Texture(sdl::Texture&&);
		Texture(sdl::Texture&&, util::Size);

		void render(util::Point offset = {}) const final;

		void alpha(sdl::Texture::Alpha) const;

		void opaque() const;
		void half_transparent() const;

		void swap(Texture&&);

	private:
		sdl::Texture m_texture;
	};
}
