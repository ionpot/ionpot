#include "solid_box.hpp"

#include "border.hpp"
#include "point.hpp"
#include "size.hpp"
#include "texture.hpp"

#include <sdl/renderer.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	Texture
	solid_box(
			std::shared_ptr<sdl::Renderer> renderer,
			Size size,
			const util::RGBA& color)
	{
		return {
			sdl::TargetTexture {renderer, size, color},
			size
		};
	}

	Texture
	solid_box(
			std::shared_ptr<sdl::Renderer> renderer,
			Size size,
			const util::RGBA& color,
			const Border& border)
	{
		sdl::TargetTexture tx {renderer, size, color};
		const auto& rdr = tx.set_as_target();
		border.draw(rdr, size);
		rdr.reset_target();
		return {std::move(tx), size};
	}
}
