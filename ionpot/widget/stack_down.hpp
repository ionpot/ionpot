#pragma once

#include "box.hpp"

#include <util/size.hpp>

namespace ionpot::widget {
	template<class T> // T = Box*[]
	void
	stack_down(T& boxes, int spacing = 0)
	{
		Box* last {nullptr};
		for (Box* box : boxes) {
			if (last)
				box->place_below(*last, spacing);
			last = box;
		}
	}

	template<class T> // T = Box*[]
	void
	stack_down(T& boxes, util::Size spacing)
	{ stack_down(boxes, spacing.height); }
}
