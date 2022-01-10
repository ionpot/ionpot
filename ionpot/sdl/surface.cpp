#include "surface.hpp"

#include "video.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	Surface::Surface(std::shared_ptr<Video> video, SDL_Surface* ptr):
		pointer {ptr},
		m_video {video}
	{}

	Surface::~Surface()
	{
		if (pointer) {
			SDL_FreeSurface(pointer);
			pointer = NULL;
		}
	}

	Surface::Surface(Surface&& from) noexcept:
		pointer {from.pointer},
		m_video {from.m_video}
	{
		from.pointer = NULL;
	}

	Surface&
	Surface::operator=(Surface&& from) noexcept
	{
		pointer = from.pointer;
		m_video = from.m_video;
		from.pointer = NULL;
		return *this;
	}
}
