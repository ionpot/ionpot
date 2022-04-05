#pragma once

#include "base.hpp"
#include "point.hpp"

#include <util/macros.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Video {
	public:
		Video(std::shared_ptr<Base>);
		~Video();
		IONPOT_NO_COPY(Video)
		IONPOT_DEFAULT_MOVE(Video)

		Point mouse_position() const;

	private:
		std::shared_ptr<Base> m_base;
	};
}
