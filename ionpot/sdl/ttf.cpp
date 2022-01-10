#include "ttf.hpp"

#include "ttf_exception.hpp"
#include "version.hpp"

#include <SDL_ttf.h>

#include <string>

namespace ionpot::sdl {
	bool
	Ttf::was_init()
	{
		return TTF_WasInit();
	}

	std::string
	Ttf::version_str()
	{
		return version::to_string(*TTF_Linked_Version());
	}

	Ttf::Ttf()
	{
		if (was_init())
			throw TtfException {"Already initialised."};

		if (TTF_Init() == -1) {
			TtfException ex;
			TTF_Quit();
			throw ex;
		}
	}

	Ttf::~Ttf()
	{
		TTF_Quit();
	}
}
