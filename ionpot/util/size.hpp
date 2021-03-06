#pragma once

#include "point.hpp" // circular dep

#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	struct Point;

	struct Size {
		int width {0};
		int height {0};

		Size() = default;
		Size(int width_and_height);
		Size(int width, int height);
		Size(const std::pair<int, int>&);

		explicit Size(const Point&);

		Point center(const Size&) const;

		Size operator+(const Size&) const;
		Size operator-(const Size&) const;
		Size operator-(int) const;
		Size operator/(int) const;
		Size& operator-=(const Size&);
		Size& operator-=(int);

		explicit operator bool() const;

		void pick_max(const Size&);

		bool shorter_than(const Size&) const;

		std::string to_str() const;
	};
}
