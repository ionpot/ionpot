#pragma once

#include "video.hpp"

#include <util/macros.hpp>
#include <util/size.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	class Window {
		friend class Renderer;

	public:
		using Flags = Uint32;
		struct Config {
			std::string title;
			util::Size size;
			Flags flags {0};
		};

		Window(std::shared_ptr<const Video>, const Config&);
		~Window();
		IONPOT_NO_COPY(Window)
		IONPOT_DECLARE_MOVE(Window)

		bool check_flags(Flags) const;
		bool has_focus() const;
		util::Size query_size() const;

	private:
		std::shared_ptr<const Video> m_video;
		SDL_Window* m_window;
	};
}
