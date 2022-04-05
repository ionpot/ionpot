#pragma once

#include "box.hpp"
#include "point.hpp"
#include "texture.hpp"

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	template<class T>
	class TextBox : public Box {
	public:
		TextBox(T&& text, Texture&& box):
			Box(box.size()),
			m_text {std::move(text)},
			m_box {std::move(box)}
		{}

		void
		render(Point offset = {0}) const
		{
			auto pos = position() + offset;
			m_box.render(pos);
			m_text.render(pos);
		}

	private:
		T m_text;
		Texture m_box;
	};

	template<class T>
	class SharedTextBox : public Box {
	public:
		SharedTextBox(T&& text, std::shared_ptr<const Texture> box):
			Box(box->size()),
			m_text {std::move(text)},
			m_box {box}
		{}

		void
		render(Point offset = {0}) const
		{
			auto pos = position() + offset;
			m_box->render(pos);
			m_text.render(pos);
		}

	private:
		T m_text;
		std::shared_ptr<const Texture> m_box;
	};
}
