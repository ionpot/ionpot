#pragma once

#include "macros.hpp"

#include <string>
#include <sstream>

#define IONPOT_FILE_LINE()\
	ionpot::util::FileLine {IONPOT_FILE, __LINE__}

namespace ionpot::util {
	struct FileLine {
		char* file;
		int line;
		std::string to_string() const
		{
			std::stringstream ss;
			ss << file << ":" << line;
			return ss.str();
		}
	};
}
