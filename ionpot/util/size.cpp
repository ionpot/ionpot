#include "size.hpp"

#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	Size::Size(int n):
		Size(n, n)
	{}
	Size::Size(int w, int h):
		width {w}, height {h}
	{}
	Size::Size(const std::pair<int, int>& p):
		Size(p.first, p.second)
	{}

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

	std::string
	Size::to_str() const
	{
		return std::to_string(width)
			+ "x"
			+ std::to_string(height);
	}
}
