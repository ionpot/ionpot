#pragma once

#include <util/point.hpp>
#include <util/size.hpp>

namespace ionpot::widget {
	class Padding {
	public:
		Padding();
		Padding(util::Size);
		Padding(util::Size content, util::Size total);
		Padding(int horizontal, int vertical);
		Padding(int both);
		util::Point offset() const;
		util::Size size() const;
	private:
		util::Point m_amount;
	};
}
