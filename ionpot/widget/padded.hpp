#pragma once

#include "box.hpp"
#include "padding.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	template<class T> // T = Box
	class Padded : public Box {
	public:
		Padded(T&& content, Padding padding = {}):
			Box(content.size() + padding.size()),
			m_content {std::move(content)},
			m_padding {padding}
		{}

		Padded(T&& content, util::Size total_size):
			Padded {
				std::move(content),
				Padding {content.size(), total_size}
			}
		{}

		void
		render(util::Point offset = {}) const
		{
			m_content.render(position() + offset + m_padding.offset());
		}

	private:
		T m_content;
		Padding m_padding;
	};
}
