#include "group.hpp"

#include "element.hpp"
#include "sum_sizes.hpp"

#include <util/point.hpp>

#include <memory> // std::shared_ptr
#include <utility> // std::move
#include <vector>

namespace ionpot::widget {
	void
	Group::elements(Elements&& ls)
	{ m_elements = std::move(ls); }

	void
	Group::groups(Groups&& ls)
	{ m_groups = std::move(ls); }

	std::shared_ptr<Element>
	Group::find(util::Point p, util::Point offset)
	{
		offset += position();
		for (auto elmt : m_elements)
			if (elmt->visible())
				if (elmt->contains(p, offset))
					return elmt;
		for (auto& group : m_groups)
			if (group->visible())
				if (auto found = group->find(p, offset))
					return found;
		return {};
	}

	void
	Group::render(util::Point offset) const
	{
		offset += position();
		for (const auto& elmt : m_elements)
			elmt->render_if_visible(offset);
		for (const auto& group : m_groups)
			group->render_if_visible(offset);
	}

	void
	Group::update_size()
	{
		std::vector<Element> ls;
		for (const auto& elmt : m_elements)
			ls.push_back(*elmt);
		for (const auto& group : m_groups)
			ls.push_back(*group);
		size(sum_sizes(ls));
	}
}
