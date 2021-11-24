#pragma once

#include "exception.hpp"

#include <fstream>
#include <list>
#include <string>

namespace ionpot::util::file {
	typedef std::list<std::string> LineList;

	IONPOT_EXCEPTION("File")

	struct OpenFailed : public Exception {
		OpenFailed(std::string filename);
	};

	std::ofstream open_w(std::string filename);

	LineList read_lines(std::string filename);
}
