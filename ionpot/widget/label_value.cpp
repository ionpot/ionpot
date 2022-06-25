#include "label_value.hpp"

#include <util/size.hpp>

namespace ionpot::widget {
	LabelValue::LabelValue(Item label, Item value, int spacing):
		m_label {label},
		m_value {value}
	{
		children({m_label, m_value});
		value_offset(m_label->size(), spacing);
	}

	util::Size
	LabelValue::label_size() const
	{ return m_label->size(); }

	void
	LabelValue::value(Item new_value)
	{
		new_value->place_on(*m_value);
		m_value = new_value;
		children({m_label, m_value});
		update_size();
	}

	void
	LabelValue::value_offset(util::Size size, int spacing)
	{
		m_value->place_after(size, spacing);
		update_size();
	}

	// helpers
	void
	align_labels(const LabelValue::Vector& labels, int spacing)
	{
		auto size = max_label_size(labels);
		for (auto& lv : labels)
			lv->value_offset(size, spacing);
	}

	void
	align_labels(const LabelValue::Vector& labels, util::Size spacing)
	{ align_labels(labels, spacing.width); }

	util::Size
	max_label_size(const LabelValue::Vector& labels)
	{
		util::Size size;
		for (const auto& lv : labels)
			size.pick_max(lv->label_size());
		return size;
	}
}
