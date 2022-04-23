#include "text_box.hpp"

#include "box.hpp"
#include "point.hpp"
#include "texture.hpp"

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	TextBox::TextBox(Texture&& text, Texture&& box):
		Box {box.size()},
		m_text {std::move(text)},
		m_box {std::move(box)}
	{
		m_text.center_to(m_box);
	}

	void
	TextBox::render(Point offset) const
	{
		auto pos = position() + offset;
		m_box.render(pos);
		m_text.render(pos);
	}

	// SharedTextBox
	SharedTextBox::SharedTextBox(
			Texture&& text,
			std::shared_ptr<const Texture> box
	):
		Box {box->size()},
		m_text {std::move(text)},
		m_box {box}
	{
		m_text.center_to(*m_box);
	}

	void
	SharedTextBox::render(Point offset) const
	{
		auto pos = position() + offset;
		m_box->render(pos);
		m_text.render(pos);
	}
}
