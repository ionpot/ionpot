#pragma once

#include "dice.hpp"
#include "exception.hpp"
#include "file.hpp"
#include "point.hpp"
#include "rgb.hpp"
#include "size.hpp"

#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	class CfgFile {
	public:
		class Pair {
		public:
			static const std::string delimiter;
			static bool is_pair(std::string line);
			std::string section;
			std::string key;
			std::string value;
			Pair(std::string line, std::string section = "");
			dice::Input to_dice() const;
			double to_double() const;
			int to_int() const;
			std::pair<int, int> to_int_pair(char delim = ' ') const;
			Point to_point() const;
			RGB to_rgb() const;
			Size to_size() const;
		private:
			template<class T>
			T to_value(T (*)(std::string)) const;
		};
		class Section {
		public:
			std::string name;
			Section(std::string name, const file::LineList&);
			Pair find_pair(std::string key) const;
		private:
			file::LineList m_lines;
		};

		CfgFile(std::string filename);

		Pair
		find_pair(std::string key) const;

		Section
		find_section(std::string name) const;

		IONPOT_EXCEPTION("CfgFile")

		struct BadValue : public Exception {
			BadValue(
				std::string key,
				std::string expected,
				std::string section = ""
			);
		};

		struct MissingKey : public Exception {
			MissingKey(std::string key, std::string section = "");
		};

		struct MissingSection : public Exception {
			MissingSection(std::string name);
		};

		struct NotPair : public Exception {
			NotPair(std::string line);
		};

	private:
		file::LineList m_lines;

		file::LineList
		find_object_lines(std::string name) const;
	};
}
