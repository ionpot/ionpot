#pragma once

#include "element.hpp"
#include "texture.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class TextBox : public Element {
	public:
		TextBox(Texture&& text, Texture&& box);

		void render(util::Point offset = {}) const;

		const Texture& text() const;

	private:
		Texture m_text;
		Texture m_box;
	};

	class SharedTextBox : public Element {
	public:
		SharedTextBox(Texture&& text, std::shared_ptr<const Texture> box);

		void render(util::Point offset = {}) const;

		const Texture& text() const;

	private:
		Texture m_text;
		std::shared_ptr<const Texture> m_box;
	};
}
