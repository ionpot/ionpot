#pragma once

#include "macros.hpp"

#include <fstream>
#include <string>
#include <utility>

namespace ionpot::util {
	struct Log {
		std::ofstream file;

		Log(std::string filename);
		~Log() = default;
		IONPOT_NO_COPY(Log)
		IONPOT_DEFAULT_MOVE(Log)

		void error(std::string);

		template<class T>
		void pair(std::string key, T value)
		{
			write_pair_key(key);
			file << std::forward<T>(value) << std::endl;
		}

		void put(std::string);

	private:
		void write_pair_key(std::string key);
	};
}
