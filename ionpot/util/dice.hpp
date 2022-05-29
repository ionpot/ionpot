#pragma once

#include "exception.hpp"

#include <random>

namespace ionpot::util::dice {
	IONPOT_EXCEPTION("Dice")

	struct Input {
		int count;
		int sides;
	};

	class Engine {
	public:
		Engine(unsigned int seed);
		int roll(const Input&);
	private:
		std::mt19937 m_engine;
	};
}
