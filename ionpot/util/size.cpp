#include "size.hpp"

#include "point.hpp"

#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	Size::Size(int n):
		Size {n, n}
	{}
	Size::Size(int w, int h):
		width {w}, height {h}
	{}
	Size::Size(const std::pair<int, int>& p):
		Size {p.first, p.second}
	{}
	Size::Size(const Point& p):
		Size {p.x, p.y}
	{}

	Point
	Size::center(const Size& size) const
	{
		return Point {(*this - size) / 2};
	}

	Size
	Size::operator+(const Size& size) const
	{
		return {width + size.width, height + size.height};
	}

	Size
	Size::operator-(const Size& size) const
	{
		return {width - size.width, height - size.height};
	}

	Size
	Size::operator-(int n) const
	{
		return *this - Size {n};
	}

	Size
	Size::operator/(int n) const
	{
		return {width / n, height / n};
	}

	Size&
	Size::operator-=(const Size& s)
	{
		*this = *this - s;
		return *this;
	}

	Size&
	Size::operator-=(int n)
	{
		*this = *this - n;
		return *this;
	}

	Size::operator bool() const
	{ return width || height; }

	void
	Size::pick_max(const Size& size)
	{
		if (width < size.width)
			width = size.width;
		if (height < size.height)
			height = size.height;
	}

	bool
	Size::shorter_than(const Size& size) const
	{ return height < size.height; }

	std::string
	Size::to_str() const
	{
		return std::to_string(width)
			+ "x"
			+ std::to_string(height);
	}
}
