#include "text.hpp"

#include "size.hpp"
#include "texture.hpp"

#include <sdl/renderer.hpp>
#include <sdl/texture.hpp>

#include <util/rgba.hpp>

#include <string>

namespace ionpot::widget {
	Texture text(
			std::shared_ptr<sdl::Renderer> renderer,
			const sdl::Font& font,
			std::string contents,
			util::RGBA color)
	{
		auto surface = font.render_blended(contents, color);
		return {
			sdl::Texture {renderer, surface},
			font.calculate_size(contents)
		};
	}
}
