#pragma once

#include "box.hpp"
#include "padding.hpp"
#include "point.hpp"
#include "size.hpp"

#include <utility> // std::move

namespace ionpot::widget {
	template<class T>
	class Padded : public Box {
	public:
		Padded(T&& content, Padding padding = {0}):
			Box(content.size() + Size {padding * 2}),
			m_content {std::move(content)},
			m_padding {padding}
		{}

		void
		render(Point offset = {0}) const
		{
			m_content.render(position() + offset + m_padding);
		}

	private:
		T m_content;
		Padding m_padding;
	};
}
