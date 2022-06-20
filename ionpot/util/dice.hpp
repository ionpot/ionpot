#pragma once

#include "exception.hpp"

#include <random>
#include <string>
#include <vector>

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

		template<class T>
		T
		pick(const std::vector<T>& ls)
		{ return ls[roll_index(ls.size())]; }

		int roll(const Input&);

		unsigned int roll_index(unsigned int size);

	private:
		std::mt19937 m_engine;
	};
}
