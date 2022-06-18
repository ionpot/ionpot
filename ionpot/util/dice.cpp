#include "dice.hpp"

#include <random>
#include <string>

namespace ionpot::util::dice {
	std::string
	Input::to_str() const
	{ return std::to_string(count) + "d" + std::to_string(sides); }

	// Engine
	Engine::Engine(unsigned int seed):
		m_engine {seed}
	{}

	int
	Engine::roll(const Input& input)
	{
		auto [count, sides] = input;
		if (sides < 1)
			throw Exception {"Dice must have at least 1 side."};
		int result {0};
		std::uniform_int_distribution<int> dist {1, sides};
		while (count--)
			result += dist(m_engine);
		return result;
	}
}
