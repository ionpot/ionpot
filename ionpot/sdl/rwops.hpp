#pragma once

#include "base.hpp"

#include <util/macros.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	class RWops {
	public:
		static RWops read_binary(
				std::shared_ptr<Base>,
				const std::string& file);

		SDL_RWops* pointer;

		RWops(std::shared_ptr<Base>,
				const std::string& file,
				const std::string& mode);
		~RWops();
		IONPOT_NO_COPY(RWops)
		IONPOT_DECLARE_MOVE(RWops)

	private:
		std::shared_ptr<Base> m_base;
	};
}
