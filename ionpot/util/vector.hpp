#pragma once

#include <vector>

namespace ionpot::util {
	template<class T, class U>
	std::vector<T*>
	ptr_vector(std::vector<U>& input)
	{
		std::vector<T*> output;
		for (auto& x : input)
			output.push_back(static_cast<T*>(&x));
		return output;
	}

	template<class T, class U>
	std::vector<T>
	vector_cast(const std::vector<U>& input)
	{
		std::vector<T> output;
		for (auto x : input)
			output.push_back(static_cast<T>(x));
		return output;
	}
}
