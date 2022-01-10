#include "version.hpp"

#include <SDL.h>

#include <string>

namespace ionpot::sdl::version {
	std::string
	as_string()
	{
		return to_string(query());
	}

	SDL_version
	query()
	{
		SDL_version ver;
		SDL_GetVersion(&ver);
		return ver;
	}

	std::string
	to_string(const SDL_version& v)
	{
		return std::to_string(v.major)
			+ "." + std::to_string(v.minor)
			+ "." + std::to_string(v.patch);
	}
}
