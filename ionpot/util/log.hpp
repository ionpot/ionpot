#pragma once

#include "macros.hpp"

#include <fstream>
#include <string>
#include <utility> // std::forward

namespace ionpot::util {
	struct Log {
		std::ofstream file;

		Log(std::string filename);
		~Log() = default;
		IONPOT_NO_COPY(Log)
		IONPOT_DEFAULT_MOVE(Log)

		void endl();

		void error(std::string);

		template<class T>
		void pair(std::string key, T value)
		{
			write(key);
			put(value);
		}

		template<class T>
		void put(T value)
		{
			write(value, "");
			endl();
		}

		template<class T>
		void write(T value, std::string suffix = " ")
		{
			file << std::forward<T>(value) << suffix;
		}
	};
}
