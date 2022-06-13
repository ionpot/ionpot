#pragma once

#include <memory> // std::shared_ptr
#include <vector>

namespace ionpot::util {
	template<class T>
	using PtrVector = std::vector<std::shared_ptr<T>>;

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
