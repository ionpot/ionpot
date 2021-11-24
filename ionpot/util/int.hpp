#pragma once

#include "exception.hpp"
#include "file_line.hpp"

#include <cstdint>
#include <string>

#define IONPOT_INT(expr)\
	ionpot::util::int_cast(expr, IONPOT_FILE_LINE(), #expr)

#define IONPOT_INT_INDEX(expr, max)\
	ionpot::util::int_index(expr, max, IONPOT_FILE_LINE(), #expr)

#define IONPOT_INT_NATURAL(expr)\
	ionpot::util::int_natural(expr, IONPOT_FILE_LINE(), #expr)

#define IONPOT_INT_POSITIVE(expr)\
	ionpot::util::int_positive(expr, IONPOT_FILE_LINE(), #expr)

#define IONPOT_INT_ROUND(expr)\
	ionpot::util::int_round(expr, IONPOT_FILE_LINE(), #expr)

#define IONPOT_INT_WITHIN(expr, max)\
	ionpot::util::int_within(expr, max, IONPOT_FILE_LINE(), #expr)

#define IONPOT_UINT8(expr)\
	ionpot::util::int_uint8(expr, IONPOT_FILE_LINE(), #expr)

namespace ionpot::util {
	IONPOT_EXCEPTION_AS(IntException, "Integer")
	int int_cast(uintmax_t, FileLine location, std::string name);
	int int_index(int n, int max, FileLine location, std::string name);
	int int_natural(int, FileLine location, std::string name);
	int int_positive(int, FileLine location, std::string name);
	int int_round(double d, FileLine loc, std::string name);
	int int_within(int n, int max, FileLine location, std::string name);
	uint8_t int_uint8(uintmax_t, FileLine location, std::string name);
}
