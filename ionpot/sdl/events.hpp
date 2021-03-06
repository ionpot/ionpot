#pragma once

#include "base.hpp"
#include "event.hpp"

#include <util/macros.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	class Events {
	public:
		Events(std::shared_ptr<const Base>);
		~Events();
		IONPOT_NO_COPY(Events)
		IONPOT_DEFAULT_MOVE(Events)

		std::optional<Event> poll() const;

	private:
		std::shared_ptr<const Base> m_base;
	};
}
