#pragma once

#include "exception.hpp"

#include <random>
#include <string>

namespace ionpot::util::dice {
	IONPOT_EXCEPTION("Dice")

	struct Input {
		int count;
		int sides;

		int min() const;
		int max() const;

		std::string to_str() const;
	};

	class Engine {
	public:
		Engine(unsigned int seed);
		int roll(const Input&);
	private:
		std::mt19937 m_engine;
	};
}
