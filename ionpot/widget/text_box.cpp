#include "text_box.hpp"

#include "element.hpp"
#include "texture.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	TextBox::TextBox(Texture&& text, Texture&& box):
		Element {box.size()},
		m_text {std::move(text)},
		m_box {std::move(box)}
	{
		m_text.center_to(m_box);
	}

	void
	TextBox::render(util::Point offset) const
	{
		auto pos = position() + offset;
		m_box.render(pos);
		m_text.render(pos);
	}

	const Texture&
	TextBox::text() const
	{ return m_text; }

	// SharedTextBox
	SharedTextBox::SharedTextBox(
			Texture&& text,
			std::shared_ptr<const Texture> box
	):
		Element {box->size()},
		m_text {std::move(text)},
		m_box {box}
	{
		m_text.center_to(*m_box);
	}

	void
	SharedTextBox::render(util::Point offset) const
	{
		auto pos = position() + offset;
		m_box->render(pos);
		m_text.render(pos);
	}

	const Texture&
	SharedTextBox::text() const
	{ return m_text; }
}
