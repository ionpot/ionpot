#include "img.hpp"

#include "img_exception.hpp"
#include "rwops.hpp"
#include "surface.hpp"
#include "version.hpp"

#include <SDL_image.h>

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

	Img::Img(Flags init_flags)
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
		Surface surface {IMG_LoadPNG_RW(rwops.pointer)};
		if (!surface.pointer)
			throw ImgException {};
		return surface;
	}
}
