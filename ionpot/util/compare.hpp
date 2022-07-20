#pragma once

namespace ionpot::util {
	template<class T>
	int
	compare(T a, T b)
	{
		if (a == b)
			return 0;
		if (a < b)
			return -1;
		return 1;
	}
}
