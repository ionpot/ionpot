#include "stringify.hpp"

#include "percent.hpp"

#include <string>

namespace ionpot::util {
	template<>
	std::string
	stringify(const char* str)
	{ return {str}; }

	template<>
	std::string
	stringify(std::string str)
	{ return str; }

	template<>
	std::string
	stringify(util::Percent p)
	{ return p.to_str(); }
}
