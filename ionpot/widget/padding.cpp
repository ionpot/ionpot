#include "padding.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	Padding::Padding():
		Padding {0}
	{}

	Padding::Padding(util::Size size):
		m_amount {util::Point {size}}
	{}

	Padding::Padding(util::Size content, util::Size total):
		Padding {(total - content) / 2}
	{}

	Padding::Padding(int horizontal, int vertical):
		Padding {util::Size {horizontal, vertical}}
	{}

	Padding::Padding(int both):
		Padding {both, both}
	{}

	util::Point
	Padding::offset() const
	{ return m_amount; }

	util::Size
	Padding::size() const
	{ return util::Size {m_amount * 2}; }
}
