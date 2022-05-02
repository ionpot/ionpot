#pragma once

#include <utility> // std::move

namespace ionpot::widget {
	template<class T> // T = Box
	void
	swap(T& dst, T&& src)
	{
		src.place_on(dst);
		dst = std::move(src);
	}
}
