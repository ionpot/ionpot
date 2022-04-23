#pragma once

#include "box.hpp"
#include "point.hpp"
#include "texture.hpp"

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class TextBox : public Box {
	public:
		TextBox(Texture&& text, Texture&& box);

		void render(Point offset = {0}) const;

	private:
		Texture m_text;
		Texture m_box;
	};

	class SharedTextBox : public Box {
	public:
		SharedTextBox(Texture&& text, std::shared_ptr<const Texture> box);

		void render(Point offset = {0}) const;

	private:
		Texture m_text;
		std::shared_ptr<const Texture> m_box;
	};
}
