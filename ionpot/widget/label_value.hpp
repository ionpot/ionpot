#pragma once

#include "element.hpp"

#include <util/size.hpp>
#include <util/vector.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class LabelValue : public Element {
	public:
		using Item = std::shared_ptr<Element>;
		using Vector = util::PtrVector<LabelValue>;

		LabelValue(Item label, Item value, int spacing = 0);

		util::Size label_size() const;

		void value(Item new_value);

		void value_offset(util::Size size, int spacing = 0);

	private:
		Item m_label;
		Item m_value;
	};

	void align_labels(const LabelValue::Vector&, int spacing = 0);
	void align_labels(const LabelValue::Vector&, util::Size spacing = {});

	util::Size max_label_size(const LabelValue::Vector&);
}
