#pragma once

#include <vector>

namespace ionpot::widget {
	template<class T> // T = Box*
	void
	side_by_side(std::vector<T>& boxes, int spacing = 0)
	{
		T prev {nullptr};
		for (auto box : boxes) {
			if (prev)
				box->place_after(*prev, spacing);
			prev = box;
		}
	}
}
