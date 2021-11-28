#pragma once

#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	struct Size {
		int width {0};
		int height {0};

		Size() = default;
		Size(int width_and_height);
		Size(int width, int height);
		Size(const std::pair<int, int>&);

		Size operator+(const Size&) const;
		Size operator-(const Size&) const;
		Size operator-(int) const;
		Size& operator-=(const Size&);
		Size& operator-=(int);

		std::string to_str() const;
	};
}
