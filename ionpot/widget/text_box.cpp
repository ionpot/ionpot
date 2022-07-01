#include "text_box.hpp"

#include "element.hpp"
#include "texture.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	TextBox::TextBox(
			std::shared_ptr<Texture> text,
			std::shared_ptr<const Texture> box
	):
		Element {box->size()},
		m_text {text},
		m_box {box}
	{
		m_text->center_to(*m_box);
	}

	void
	TextBox::half_transparent() const
	{
		m_box->half_transparent();
		m_text->half_transparent();
	}

	void
	TextBox::opaque() const
	{
		m_box->opaque();
		m_text->opaque();
	}

	void
	TextBox::render(util::Point offset) const
	{
		offset += position();
		m_box->render(offset);
		m_text->render(offset);
	}
}
