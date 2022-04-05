#include "rwops.hpp"

#include "base.hpp"
#include "exception.hpp"

#include <SDL.h>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	RWops
	RWops::read_binary(
			std::shared_ptr<const Base> base,
			const std::string& file)
	{
		return {base, file, "rb"};
	}

	RWops::RWops(
			std::shared_ptr<const Base> base,
			const std::string& file,
			const std::string& mode):
		pointer {SDL_RWFromFile(file.c_str(), mode.c_str())},
		m_base {base}
	{
		if (!pointer)
			throw Exception {};
	}

	RWops::~RWops()
	{
		if (pointer) {
			SDL_RWclose(pointer);
			pointer = NULL;
		}
	}

	RWops::RWops(RWops&& from) noexcept:
		pointer {from.pointer},
		m_base {from.m_base}
	{
		from.pointer = NULL;
	}

	RWops&
	RWops::operator=(RWops&& from) noexcept
	{
		pointer = from.pointer;
		m_base = from.m_base;
		from.pointer = NULL;
		return *this;
	}
}
