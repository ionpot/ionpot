#pragma once

#include <util/size.hpp>
#include <util/vector.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	template<class T> // T = Box
	void
	stack_down(util::PtrVector<T>& boxes, int spacing = 0)
	{
		std::shared_ptr<T> last {};
		for (auto& box : boxes) {
			if (last)
				box->place_below(*last, spacing);
			last = box;
		}
	}

	template<class T> // T = Box
	void
	stack_down(util::PtrVector<T>& boxes, util::Size spacing)
	{ stack_down(boxes, spacing.height); }
}
