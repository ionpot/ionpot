#include "cfg_file.hpp"

#include "dice.hpp"
#include "file.hpp"
#include "point.hpp"
#include "rgb.hpp"
#include "size.hpp"
#include "string.hpp"

#include <stdexcept> // std::invalid_argument
#include <string>
#include <utility> // std::pair

namespace ionpot::util {
	namespace {
		struct s_BadValue : public CfgFile::Exception {
			const std::string expected;
			s_BadValue(std::string expected):
				CfgFile::Exception {"Value is not " + expected + "."},
				expected {expected}
			{}
		};

		std::string
		s_key_str(std::string key, std::string section)
		{
			auto q = string::quote;
			if (section.empty())
				return q(key);
			return q(section) + " -> " + q(key);
		}

		double
		s_to_double(std::string input)
		try {
			return std::stod(input);
		}
		catch (const std::invalid_argument&) {
			throw s_BadValue {"a double"};
		}

		int
		s_to_int(std::string input)
		try {
			return std::stoi(input);
		}
		catch (const std::invalid_argument&) {
			throw s_BadValue {"an integer"};
		}

		std::pair<int, int>
		s_to_int_pair(std::string input, char delimiter)
		try {
			auto i = input.find(delimiter);
			if (i == std::string::npos) {
				auto x = s_to_int(input);
				return {x, x};
			}
			return {
				s_to_int(input.substr(0, i)),
				s_to_int(input.substr(i + 1))
			};
		}
		catch (const s_BadValue&) {
			throw s_BadValue {"an integer pair"};
		}
	}

	const std::string
	CfgFile::Pair::delimiter = " = ";

	bool
	CfgFile::Pair::is_pair(std::string line)
	{
		auto i = line.find(delimiter);
		return i != std::string::npos;
	}

	CfgFile::Pair::Pair(std::string line, std::string section):
		section {section}
	{
		auto i = line.find(delimiter);
		if (i == std::string::npos)
			throw NotPair {line};
		key = line.substr(0, i);
		value = line.substr(i + delimiter.size());
	}

	dice::Input
	CfgFile::Pair::to_dice() const
	try {
		auto [left, right] = s_to_int_pair(value, 'd');
		return {left, right};
	}
	catch (const s_BadValue&) {
		throw BadValue {key, "a dice notation",  section};
	}

	double
	CfgFile::Pair::to_double() const
	{
		return to_value(s_to_double);
	}

	int
	CfgFile::Pair::to_int() const
	{
		return to_value(s_to_int);
	}

	std::pair<int, int>
	CfgFile::Pair::to_int_pair(char delimiter) const
	try {
		return s_to_int_pair(value, delimiter);
	}
	catch (const s_BadValue& err) {
		throw BadValue {key, err.expected, section};
	}

	Point
	CfgFile::Pair::to_point() const
	{
		return {to_int_pair()};
	}

	RGB
	CfgFile::Pair::to_rgb() const
	{
		return RGB::from_hex(value);
	}

	Size
	CfgFile::Pair::to_size() const
	{
		return {to_int_pair()};
	}

	template<class T>
	T
	CfgFile::Pair::to_value(
			T (*parse)(std::string)
	) const
	try {
		return parse(value);
	}
	catch (const s_BadValue& err) {
		throw BadValue {key, err.expected, section};
	}

	CfgFile::Section::Section(
			std::string name,
			const file::LineList& lines
	):
		name {name}
	{
		bool section_found {false};
		for (auto const& line : lines) {
			if (section_found) {
				if (line.empty())
					continue;
				if (line.front() != '\t')
					break;
				m_lines.push_back(line.substr(1));
			}
			else if (line == (name + ":")) {
				section_found = true;
			}
		}
		if (!section_found)
			throw MissingSection {name};
	}

	CfgFile::Pair
	CfgFile::Section::find_pair(std::string key) const
	{
		for (auto const& line : m_lines) {
			if (Pair::is_pair(line)) {
				Pair pair {line, name};
				if (pair.key == key)
					return pair;
			}
		}
		throw MissingKey {key, name};
	}

	CfgFile::CfgFile(std::string filename):
		m_lines {file::read_lines(filename)}
	{}

	CfgFile::Pair
	CfgFile::find_pair(std::string key) const
	{
		for (auto const& line : m_lines) {
			if (!Pair::is_pair(line))
				continue;
			Pair pair {line};
			if (pair.key == key)
				return pair;
		}
		throw MissingKey {key};
	}

	CfgFile::Section
	CfgFile::find_section(std::string name) const
	{
		return Section {name, m_lines};
	}

	CfgFile::BadValue::BadValue(
			std::string key,
			std::string expected,
			std::string section
	):
		Exception {s_key_str(key, section) + " is not " + expected + "."}
	{}

	CfgFile::MissingKey::MissingKey(
			std::string key,
			std::string section
	):
		Exception {"Key not found: " + s_key_str(key, section)}
	{}

	CfgFile::MissingSection::MissingSection(std::string name):
		Exception {"Missing section: " + name}
	{}

	CfgFile::NotPair::NotPair(std::string line):
		Exception {"Line is not a pair -> " + line}
	{}
}
