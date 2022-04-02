#pragma once

#include "texture.hpp"

#include <sdl/font.hpp>
#include <sdl/renderer.hpp>

#include <util/rgba.hpp>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::widget {
	Texture text(
		std::shared_ptr<sdl::Renderer>,
		const sdl::Font&,
		const util::RGBA&,
		std::string contents);
}
