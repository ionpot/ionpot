#include "scale.hpp"

#include "int.hpp"
#include "percent.hpp"

#include <math.h> // ceil, floor

namespace ionpot::util {
	Scale::Scale(double multiplier):
		m_multiplier {multiplier}
	{}

	int
	Scale::apply_to(int input) const
	{
		if (m_multiplier == 1.0)
			return input;
		double a {m_multiplier * input};
		double b {m_multiplier < 1.0 ? ceil(a) : floor(a)};
		return IONPOT_INT_ROUND(b);
	}

	Percent
	Scale::apply_to(const Percent& input) const
	{ return {apply_to(input.value())}; }
}
