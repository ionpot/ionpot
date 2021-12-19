#pragma once

#include "key.hpp"
#include "point.hpp"

#include <SDL.h>
#include <variant>

namespace ionpot::sdl {
	class KeyEvent {
		friend class Event;
	public:
		bool pressed {false};
		Key key {Key::other};
	private:
		KeyEvent(bool, SDL_Keycode);
	};

	class MouseMoveEvent {
		friend class Event;
	public:
		Point position;
	private:
		MouseMoveEvent() = default;
	};

	class QuitEvent {
		friend class Event;
	private:
		QuitEvent() = default;
	};

	class WindowEvent {
		friend class Event;
	public:
		bool got_focus() const;
		bool lost_focus() const;
	private:
		Uint8 m_id;
		WindowEvent(Uint8);
	};

	class Event {
		friend class Base;
	public:
		template<class T>
		const T* get() const
		{
			return std::get_if<T>(&m_data);
		}
	private:
		std::variant<
			std::monostate,
			KeyEvent,
			MouseMoveEvent,
			QuitEvent,
			WindowEvent
		> m_data;
		Event() = default;
		Event(const SDL_Event&);
	};
}
