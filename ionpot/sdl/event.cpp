#include "event.hpp"

#include "key.hpp"

#include <util/point.hpp>

#include <SDL.h>

#include <optional>
#include <utility> // std::move

namespace ionpot::sdl {
	Event::Event(SDL_Event&& event):
		m_event {std::move(event)}
	{}

	bool
	Event::focus_gained() const
	{
		return m_event.type == SDL_WINDOWEVENT
			&& m_event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED;
	}

	bool
	Event::focus_lost() const
	{
		return m_event.type == SDL_WINDOWEVENT
			&& m_event.window.event == SDL_WINDOWEVENT_FOCUS_LOST;
	}

	std::optional<Key>
	Event::key_down() const
	{
		if (m_event.type == SDL_KEYDOWN) {
			return {Key {m_event.key}};
		}
		return {};
	}

	std::optional<Key>
	Event::key_up() const
	{
		if (m_event.type == SDL_KEYUP) {
			return {Key {m_event.key}};
		}
		return {};
	}

	std::optional<util::Point>
	Event::lmb_down() const
	{
		if (m_event.type == SDL_MOUSEBUTTONDOWN) {
			const auto& event = m_event.button;
			if (event.button == SDL_BUTTON_LEFT) {
				return {util::Point {event.x, event.y}};
			}
		}
		return {};
	}

	std::optional<util::Point>
	Event::lmb_up() const
	{
		if (m_event.type == SDL_MOUSEBUTTONUP) {
			const auto& event = m_event.button;
			if (event.button == SDL_BUTTON_LEFT) {
				return {util::Point {event.x, event.y}};
			}
		}
		return {};
	}

	std::optional<util::Point>
	Event::mouse_move() const
	{
		if (m_event.type == SDL_MOUSEMOTION) {
			auto motion = m_event.motion;
			return {util::Point {motion.x, motion.y}};
		}
		return {};
	}

	bool
	Event::quit() const
	{
		return m_event.type == SDL_QUIT;
	}
}
