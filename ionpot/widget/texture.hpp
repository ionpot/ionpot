#pragma once

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/texture.hpp>

namespace ionpot::widget {
	class Texture : public Box {
	public:
		Texture(sdl::Texture&&);
		Texture(sdl::Texture&&, Size);

		void render(Point offset = {}) const;

	private:
		sdl::Texture m_texture;
	};
}
