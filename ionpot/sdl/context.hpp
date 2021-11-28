#pragma once

#include "base.hpp"
#include "event.hpp"
#include "img.hpp"
#include "renderer.hpp"
#include "size.hpp"
#include "texture.hpp"
#include "ttf.hpp"
#include "window.hpp"

#include <util/log.hpp>
#include <util/macros.hpp>

#include <optional>
#include <string>

namespace ionpot::sdl {
	struct Context {
		// these three must be initialised in this order
		Base base;
		Window window;
		Renderer renderer;

		// these need the above initialised
		Img img;
		Ttf ttf;

		Context(std::string window_title, Size window_size, util::Log&);
		~Context() = default;
		IONPOT_NO_COPY(Context)

		Texture load_png(std::string path) const;
		std::optional<Event> poll_event();
	};
}
