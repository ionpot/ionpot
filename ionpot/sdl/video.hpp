#pragma once

#include "base.hpp"

#include <util/macros.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Video {
	public:
		Video(std::shared_ptr<const Base>);
		~Video();
		IONPOT_NO_COPY(Video)
		IONPOT_DEFAULT_MOVE(Video)

	private:
		std::shared_ptr<const Base> m_base;
	};
}
