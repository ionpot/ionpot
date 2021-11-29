#include "scroll.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <string>

namespace ionpot::sdl {
	Scroll::Scroll(util::Size screen, util::Size content, int speed):
		m_max {util::Point::max(util::Point {content - screen})},
		m_speed {speed},
		m_state {}
	{}

	util::Point
	Scroll::next(util::Point p) const
	{
		auto q = util::Point::max({p + m_state});
		return util::Point::min(q, m_max);
	}

	void
	Scroll::start_down()
	{
		m_state.y = m_speed;
	}

	void
	Scroll::start_left()
	{
		m_state.x = -m_speed;
	}

	void
	Scroll::start_right()
	{
		m_state.x = m_speed;
	}

	void
	Scroll::start_up()
	{
		m_state.y = -m_speed;
	}

	void
	Scroll::stop()
	{
		m_state.clear();
	}

	void
	Scroll::stop_down()
	{
		if (m_state.y > 0)
			m_state.y = 0;
	}

	void
	Scroll::stop_left()
	{
		if (m_state.x < 0)
			m_state.x = 0;
	}

	void
	Scroll::stop_right()
	{
		if (m_state.x > 0)
			m_state.x = 0;
	}

	void
	Scroll::stop_up()
	{
		if (m_state.y < 0)
			m_state.y = 0;
	}

	std::string
	Scroll::to_str() const
	{
		return "max " + m_max.to_str();
	}
}
