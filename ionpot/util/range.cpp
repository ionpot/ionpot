#include "range.hpp"

#include <string>

namespace ionpot::util {
	std::string
	Range::to_str() const
	{
		auto str = std::to_string(min);
		if (min != max)
			str += "-" + std::to_string(max);
		return str;
	}
}
