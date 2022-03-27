#include "log.hpp"

#include "file.hpp"

#include <string>

namespace ionpot::util {
	Log::Log(std::string filename):
		file {file::open_w(filename)}
	{
		file.precision(2);
	}

	void
	Log::endl()
	{
		file << "\n";
	}

	void
	Log::error(std::string text)
	{
		put("[Error] " + text);
	}
}
