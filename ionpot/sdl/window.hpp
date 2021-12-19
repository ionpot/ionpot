#pragma once

#include "event.hpp"
#include "renderer.hpp"

#include <util/macros.hpp>
#include <util/point.hpp>
#include <util/size.hpp>

#include <SDL.h>
#include <string>

namespace ionpot::sdl {
	class Window {
		friend struct Context;

	public:
		typedef Uint32 Flags;

		bool has_focus() const;
		util::Point mouse_position() const;

	private:
		bool m_focus;
		util::Point m_mouse_pos;
		SDL_Window* m_window;

		Window(std::string title, util::Size window_size);
		~Window();
		IONPOT_NO_COPY(Window)

		bool check_flags(Flags) const;
		Renderer create_renderer() const;
		void handle(const Event&);
	};
}
