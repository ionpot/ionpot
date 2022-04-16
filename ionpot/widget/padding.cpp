#include "padding.hpp"

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	Padding::Padding(Size size):
		m_amount {Point {size}}
	{}

	Padding::Padding(int horizontal, int vertical):
		Padding {Size {horizontal, vertical}}
	{}

	Padding::Padding(int both):
		Padding {both, both}
	{}

	Point
	Padding::offset() const
	{ return m_amount; }

	Size
	Padding::size() const
	{ return Size {m_amount * 2}; }
}
