#pragma once

#include "point.hpp"
#include "size.hpp"

namespace ionpot::widget {
	class Padding {
	public:
		Padding();
		Padding(Size);
		Padding(Size content, Size total);
		Padding(int horizontal, int vertical);
		Padding(int both);
		Point offset() const;
		Size size() const;
	private:
		Point m_amount;
	};
}
