#pragma once

#include <string>

namespace ionpot::util {
	struct Range {
		int min;
		int max;
		std::string to_str() const;
	};
}
