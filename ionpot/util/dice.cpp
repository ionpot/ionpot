#include "dice.hpp"

#include <random>
#include <vector>

namespace ionpot::util::dice {
	Output::Output(const Input& input):
		m_sides {input.sides},
		m_rolls {}
	{ m_rolls.reserve(input.count); }

	void
	Output::add(int roll)
	{ m_rolls.push_back(roll); }

	int
	Output::count() const
	{ return m_rolls.size(); }

	const std::vector<int>&
	Output::rolls() const
	{ return m_rolls; }

	int
	Output::sides() const
	{ return m_sides; }

	int
	Output::total() const
	{
		int sum {0};
		for (auto i : m_rolls)
			sum += i;
		return sum;
	}

	// Engine
	Engine::Engine(unsigned int seed):
		m_engine {seed}
	{}

	Output
	Engine::roll(const Input& input)
	{
		auto [count, sides] = input;
		if (sides < 1)
			throw Exception {"Dice must have at least 1 side."};
		Output output {input};
		std::uniform_int_distribution<int> dist {1, sides};
		while (count--)
			output.add(dist(m_engine));
		return output;
	}
}
