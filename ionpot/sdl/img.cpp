#include "img.hpp"

#include "img_exception.hpp"
#include "rwops.hpp"
#include "surface.hpp"
#include "version.hpp"
#include "video.hpp"

#include <SDL_image.h>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	const Img::Flags
	Img::default_flags {IMG_INIT_PNG};

	bool
	Img::was_init {false};

	std::string
	Img::version_str()
	{
		return version::to_string(*IMG_Linked_Version());
	}

	Img::Img(
			std::shared_ptr<Video> video,
			Flags init_flags):
		m_video {video}
	{
		if (was_init)
			throw ImgException {"Already initialised."};

		auto flags = IMG_Init(init_flags) & init_flags;
		if (flags != init_flags) {
			ImgException ex;
			IMG_Quit();
			throw ex;
		}

		was_init = true;
	}

	Img::~Img()
	{
		IMG_Quit();
		was_init = false;
	}

	Surface
	Img::load_png(const RWops& rwops) const
	{
		Surface surface {m_video, IMG_LoadPNG_RW(rwops.pointer)};
		if (!surface.pointer)
			throw ImgException {};
		return surface;
	}
}
