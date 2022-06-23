#pragma once

#include "box.hpp"
#include "element.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <memory> // std::make_shared, std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	template<class T, class U> // T = Texture, U = Texture
	class LabelValue : public Element {
	public:
		LabelValue(T&& label, int spacing = 0):
			Element {label.size()},
			m_label {std::make_shared<T>(std::move(label))}
		{
			children({m_label});
			value_offset(size(), spacing);
		}

		LabelValue(T&& label, U&& value, int spacing = 0):
			m_label {std::make_shared<T>(std::move(label))},
			m_value {std::make_shared<U>(std::move(value))}
		{
			children({m_label, m_value});
			value_offset(m_label->size(), spacing);
		}

		util::Size
		label_size() const
		{ return m_label->size(); }

		void
		value(U&& new_value)
		{
			m_value = std::make_shared<U>(std::move(new_value));
			m_value->position(m_value_offset);
			children({m_label, m_value});
			update_size();
		}

		void
		value_offset(util::Size size, int spacing = 0)
		{
			Box box;
			box.place_after(size, spacing);
			m_value_offset = box.position();
			if (m_value) {
				m_value->position(m_value_offset);
				update_size();
			}
		}

	private:
		std::shared_ptr<T> m_label;
		std::shared_ptr<U> m_value;
		util::Point m_value_offset;
	};

	template<class T> // T = LabelValue*[]
	void
	align_labels(const T& labels, int spacing = 0)
	{
		auto size = max_label_size(labels);
		for (auto lv : labels)
			lv->value_offset(size, spacing);
	}

	template<class T> // T = LabelValue*[]
	void
	align_labels(const T& labels, util::Size spacing)
	{ align_labels(labels, spacing.width); }

	template<class T> // T = const LabelValue*[]
	util::Size
	max_label_size(const T& labels)
	{
		util::Size size;
		for (auto lv : labels)
			size.pick_max(lv->label_size());
		return size;
	}
}
