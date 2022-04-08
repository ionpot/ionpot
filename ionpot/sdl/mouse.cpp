#include "mouse.hpp"

#include "point.hpp"
#include "video.hpp"

#include <util/value.hpp>

#include <memory> // std::shared_ptr
#include <optional>

namespace ionpot::sdl {
	Mouse::Mouse(std::shared_ptr<const Video> video):
		m_video {video},
		m_position {}
	{ update(); }

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
}
