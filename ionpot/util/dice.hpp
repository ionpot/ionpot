#pragma once

#include "exception.hpp"

#include <random>
#include <vector>

namespace ionpot::util::dice {
	IONPOT_EXCEPTION("Dice")

	struct Input {
		int count;
		int sides;
	};

	class Output {
	public:
		Output(const Input&);
		void add(int);
		int count() const;
		const std::vector<int>& rolls() const;
		int sides() const;
		int total() const;
	private:
		int m_sides;
		std::vector<int> m_rolls;
	};

	class Engine {
	public:
		Engine(unsigned int seed);
		Output roll(const Input&);
	private:
		std::mt19937 m_engine;
	};
}
