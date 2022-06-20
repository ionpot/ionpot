#pragma once

#include "element.hpp"

#include <util/point.hpp>
#include <util/vector.hpp>

#include <memory> // std::shared_ptr

namespace ionpot::widget {
	class Group : public Element {
	public:
		using Elements = util::PtrVector<Element>;
		using Groups = util::PtrVector<Group>;

		std::shared_ptr<Element>
			find(util::Point, util::Point offset = {});

		void render(util::Point offset = {}) const final;

		void update_size();

	protected:
		Elements& elements();
		void elements(Elements&&);
		void groups(Groups&&);

	private:
		Elements m_elements;
		Groups m_groups;
	};
}
