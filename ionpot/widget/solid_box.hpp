#pragma once

#include "border.hpp"
#include "size.hpp"
#include "texture.hpp"

#include <sdl/renderer.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	Texture solid_box(
		std::shared_ptr<const sdl::Renderer>,
		Size,
		const util::RGBA&);

	Texture solid_box(
		std::shared_ptr<const sdl::Renderer>,
		Size,
		const util::RGBA&,
		const Border&);
}
