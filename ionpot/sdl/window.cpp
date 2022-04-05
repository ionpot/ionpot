#include "window.hpp"

#include "exception.hpp"
#include "size.hpp"
#include "video.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	Window::Window(std::shared_ptr<const Video> video, const Config& config):
		m_video {video},
		m_window {SDL_CreateWindow(
			config.title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			config.size.width,
			config.size.height,
			config.flags)}
	{
		if (!m_window)
			throw Exception {};
	}

	Window::~Window()
	{
		if (m_window) {
			SDL_DestroyWindow(m_window);
			m_window = NULL;
		}
	}

	Window::Window(Window&& from) noexcept:
		m_video {from.m_video},
		m_window {from.m_window}
	{
		from.m_window = NULL;
	}

	Window&
	Window::operator=(Window&& from) noexcept
	{
		m_video = from.m_video;
		m_window = from.m_window;
		from.m_window = NULL;
		return *this;
	}

	bool
	Window::check_flags(Flags flags) const
	{
		return SDL_GetWindowFlags(m_window) & flags;
	}

	bool
	Window::has_focus() const
	{
		return check_flags(SDL_WINDOW_INPUT_FOCUS);
	}

	Size
	Window::query_size() const
	{
		int width {0};
		int height {0};
		SDL_GetWindowSize(m_window, &width, &height);
		return {width, height};
	}
}
