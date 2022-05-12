#pragma once

#include "box.hpp"
#include "element.hpp"
#include "padding.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	template<class T> // T = Box
	class Padded : public Element {
	public:
		Padded(T&& content, Padding padding = {}):
			Element {content.size() + padding.size()},
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
			Element::render(m_content, offset + m_padding.offset());
		}

	private:
		T m_content;
		Padding m_padding;
	};
}
