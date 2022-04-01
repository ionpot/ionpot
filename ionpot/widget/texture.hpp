#pragma once

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/font.hpp>
#include <sdl/renderer.hpp>
#include <sdl/texture.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::widget {
	class Texture : public Box {
	public:
		Texture(sdl::Texture&&);
		Texture(sdl::Texture&&, Size);

		Texture(
			std::shared_ptr<sdl::Renderer>,
			const sdl::Font&,
			const util::RGBA&,
			std::string text);

		void render(Point offset = {0}) const;

	private:
		sdl::Texture m_texture;
	};
}
