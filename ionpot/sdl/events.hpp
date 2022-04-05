#pragma once

#include "base.hpp"
#include "event.hpp"
#include "point.hpp"

#include <util/macros.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Events {
	public:
		Events(std::shared_ptr<Base>);
		~Events();
		IONPOT_NO_COPY(Events)
		IONPOT_DEFAULT_MOVE(Events)

		std::optional<Event> poll() const;

		Point mouse_position() const;

	private:
		std::shared_ptr<Base> m_base;
	};
}
