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
	{}

	Point
	Mouse::position() const
	{ return m_position.current(); }

	std::optional<Point>
	Mouse::moved() const
	{ return m_position.changed(); }

	void
	Mouse::update()
	{ update(m_video->mouse_position()); }

	void
	Mouse::update(Point new_mouse_pos)
	{ m_position = new_mouse_pos; }
}
