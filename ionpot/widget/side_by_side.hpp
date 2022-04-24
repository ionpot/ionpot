#pragma once

namespace ionpot::widget {
	template<class T> // T = Box[]
	void
	side_by_side(T& boxes, int spacing = 0)
	{
		auto a = boxes.begin();
		auto b = a;
		while (++b < boxes.end()) {
			b->place_after(*a, spacing);
			a = b;
		}
	}
}
