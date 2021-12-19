#pragma once

#include "event.hpp"
#include "point.hpp"
#include "renderer.hpp"
#include "size.hpp"

#include <util/macros.hpp>

#include <SDL.h>
#include <string>

namespace ionpot::sdl {
	class Window {
		friend struct Context;

	public:
		typedef Uint32 Flags;

		bool has_focus() const;
		Point mouse_position() const;

	private:
		bool m_focus;
		Point m_mouse_pos;
		SDL_Window* m_window;

		Window(std::string title, Size window_size);
		~Window();
		IONPOT_NO_COPY(Window)

		bool check_flags(Flags) const;
		Renderer create_renderer() const;
		void handle(const Event&);
	};
}
