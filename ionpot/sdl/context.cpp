#include "context.hpp"

#include "event.hpp"
#include "texture.hpp"

#include <util/log.hpp>
#include <util/size.hpp>

#include <optional>
#include <string>

namespace ionpot::sdl {
	Context::Context(std::string title, util::Size window_size, util::Log& log):
		base {log},
		window {title, window_size},
		renderer {window.create_renderer()},
		img {log},
		ttf {log}
	{}

	Texture
	Context::load_png(std::string path) const
	{
		auto rwops = base.read_binary_file(path);
		auto surface = img.load_png(rwops);
		return renderer.create_texture(surface);
	}

	std::optional<Event>
	Context::poll_event()
	{
		auto event = base.poll_event();
		if (event)
			window.handle(*event);
		return event;
	}
}
