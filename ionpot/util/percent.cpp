#include "percent.hpp"

#include <string>

namespace ionpot::util {
	Percent::Percent(int value):
		m_value {value}
	{}

	Percent
	Percent::operator+(const Percent& p)
	{ return {value() + p.value()}; }

	bool
	Percent::success(int value) const
	{ return value <= m_value; }

	std::string
	Percent::to_str() const
	{ return std::to_string(m_value) + "%"; }

	int
	Percent::value() const
	{ return m_value; }
}
