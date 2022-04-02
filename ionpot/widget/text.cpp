#include "text.hpp"

#include "texture.hpp"

#include <sdl/font.hpp>
#include <sdl/renderer.hpp>
#include <sdl/texture.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::widget {
	Texture
	text(
			std::shared_ptr<sdl::Renderer> renderer,
			const sdl::Font& font,
			const util::RGBA& color,
			std::string contents)
	{
		return {
			sdl::Texture {
				renderer,
				font.render_blended(contents, color)
			},
			font.calculate_size(contents)
		};
	}
}
