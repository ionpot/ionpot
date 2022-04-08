#include "mouse.hpp"

#include "event.hpp"
#include "point.hpp"
#include "video.hpp"

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	Mouse::Mouse(std::shared_ptr<const Video> video):
		m_video {video},
		m_position {},
		m_lmb_down {false}
	{ update(); }

	bool
	Mouse::lmb_down() const
	{ return m_lmb_down; }

	std::optional<Point>
	Mouse::moved() const
	{ return m_position.changed(); }

	Point
	Mouse::position() const
	{ return m_position.current(); }

	Point
	Mouse::query_position() const
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return {x, y};
	}

	void
	Mouse::update()
	{ update(query_position()); }

	void
	Mouse::update(Point new_mouse_pos)
	{ m_position = new_mouse_pos; }

	std::optional<Mouse::LeftClick>
	Mouse::update(const Event& event)
	{
		if (auto pos = event.lmb_up()) {
			if (m_lmb_down) {
				m_lmb_down = false;
				return pos;
			}
		}
		else if (event.lmb_down()) {
			m_lmb_down = true;
		}
		else if (event.focus_lost()) {
			m_lmb_down = false;
		}
		return {};
	}
}
