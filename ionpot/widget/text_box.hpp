#pragma once

#include "box.hpp"
#include "padding.hpp"
#include "point.hpp"
#include "texture.hpp"

#include <utility> // std::move

namespace ionpot::widget {
	template<class T> // unique_ptr or shared_ptr<const Texture>
	class TextBox : public Box {
	public:
		TextBox(Texture&& text, T&& box):
			Box(box->size()),
			m_text {std::move(text)},
			m_box {std::move(box)}
		{}

		TextBox(Texture&& text, T&& box, const Padding& padding):
			TextBox(std::move(text), std::move(box))
		{
			m_text.position(padding.offset());
		}

		void
		render(Point offset = {0}) const
		{
			auto pos = position() + offset;
			m_box->render(pos);
			m_text.render(pos);
		}

	private:
		Texture m_text;
		T m_box;
	};
}
