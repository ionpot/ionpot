#include "stringify.hpp"

#include "percent.hpp"
#include "range.hpp"

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
	stringify(Percent p)
	{ return p.to_str(); }

	template<>
	std::string
	stringify(Range r)
	{ return r.to_str(); }
}
