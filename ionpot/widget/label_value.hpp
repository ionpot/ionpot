#pragma once

#include "box.hpp"
#include "element.hpp"
#include "sum_sizes.hpp"
#include "swap.hpp"
#include "texture.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <optional>
#include <utility> // std::move
#include <vector>

namespace ionpot::widget {
	template<class T, class U> // T = Texture, U = Texture
	class LabelValue : public Element {
	public:
		LabelValue(T&& label, int spacing = 0):
			Element {label.size()},
			m_label {std::move(label)},
			m_value {},
			m_value_offset {}
		{
			value_offset(size(), spacing);
		}

		LabelValue(T&& label, U&& value, int spacing = 0):
			Element {},
			m_label {std::move(label)},
			m_value {std::move(value)},
			m_value_offset {}
		{
			value_offset(label.size(), spacing);
		}

		util::Size
		label_size() const
		{ return m_label.size(); }

		void
		render(util::Point offset = {}) const
		{
			auto pos = position() + offset;
			m_label.render(pos);
			if (m_value)
				m_value->render(pos);
		}

		void
		update_size()
		{
			std::vector<Element> ls {m_label};
			if (m_value)
				ls.push_back(*m_value);
			size(sum_sizes(ls));
		}

		void
		value(U&& new_value)
		{
			m_value = std::move(new_value);
			m_value->position(m_value_offset);
			update_size();
		}

		void
		value_offset(util::Size size, int spacing = 0)
		{
			Box box {m_label};
			box.place_after(size, spacing);
			m_value_offset = box.position();
			if (m_value) {
				m_value->position(m_value_offset);
				update_size();
			}
		}

	private:
		T m_label;
		std::optional<U> m_value;
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
