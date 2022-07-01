#pragma once

#include "element.hpp"
#include "texture.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class TextBox : public Element {
	public:
		TextBox(
			std::shared_ptr<Texture> text,
			std::shared_ptr<const Texture> box);

		void render(util::Point offset = {}) const override;

		void opaque() const;
		void half_transparent() const;

	private:
		std::shared_ptr<Texture> m_text;
		std::shared_ptr<const Texture> m_box;
	};
}
