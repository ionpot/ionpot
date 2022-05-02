#pragma once

#include "box.hpp"
#include "swap.hpp"
#include "texture.hpp"

#include <util/point.hpp>
#include <util/size.hpp>

#include <utility> // std::move
#include <vector>

namespace ionpot::widget {
	template<class T, class U> // T = Texture, U = Texture
	class LabelValue : public Box {
	public:
		LabelValue(T&& label, U&& value, int spacing = 0):
			Box {},
			m_label {std::move(label)},
			m_value {std::move(value)}
		{
			m_value.place_after(m_label, spacing);
			size(sum_sizes(std::vector<const Box*> {&m_label, &m_value}));
		}

		util::Size
		label_size() const
		{
			return util::Size {m_value.position()};
		}

		void
		label_size(util::Size size, int spacing = 0)
		{
			Box box {size, m_label.position()};
			m_value.place_after(box, spacing);
		}

		void
		render(util::Point offset = {}) const
		{
			auto pos = position() + offset;
			m_label.render(pos);
			m_value.render(pos);
		}

		void
		value(U&& new_value)
		{
			swap(m_value, std::move(new_value));
		}

	private:
		T m_label;
		U m_value;
	};

	template<class T> // T = LabelValue*[]
	void
	align_labels(const T& labels, int spacing = 0)
	{
		auto size = max_label_size(labels);
		for (auto lv : labels)
			lv->label_size(size, spacing);
	}

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
