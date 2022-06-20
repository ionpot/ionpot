#pragma once

#include <string>

namespace ionpot::util {
	class Percent {
	public:
		Percent(int);

		bool success(int) const;
		int value() const;

		Percent operator+(const Percent&);

		std::string to_str() const;

	private:
		int m_value;
	};
}
