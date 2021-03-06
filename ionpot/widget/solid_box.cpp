#include "solid_box.hpp"

#include "border.hpp"
#include "texture.hpp"

#include <sdl/renderer.hpp>

#include <util/point.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	Texture
	solid_box(
			std::shared_ptr<const sdl::Renderer> renderer,
			util::Size size,
			const util::RGBA& color)
	{
		return {
			sdl::TargetTexture {renderer, size, color},
			size
		};
	}

	Texture
	solid_box(
			std::shared_ptr<const sdl::Renderer> renderer,
			util::Size size,
			const util::RGBA& color,
			const Border& border)
	{
		sdl::TargetTexture tx {renderer, size, color};
		tx.set_as_target();
		border.draw(*renderer, size);
		renderer->reset_target();
		return {std::move(tx), size};
	}
}
