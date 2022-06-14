#pragma once

#include "percent.hpp"

#include <string>

namespace ionpot::util {
	template<class T>
	std::string
	stringify(T value)
	{ return std::to_string(value); }

	template<>
	std::string
	stringify(const char*);

	template<>
	std::string
	stringify(std::string);

	template<>
	std::string
	stringify(util::Percent);
}
