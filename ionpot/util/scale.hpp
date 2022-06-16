#pragma once

#include "percent.hpp"

namespace ionpot::util {
	class Scale {
	public:
		Scale(double multiplier = 1.0);

		int apply_to(int) const;
		Percent apply_to(const Percent&) const;

	private:
		double m_multiplier;
	};
}
