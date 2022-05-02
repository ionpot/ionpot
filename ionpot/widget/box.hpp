#pragma once

#include <util/point.hpp>
#include <util/size.hpp>
#include <util/vector.hpp>

#include <vector>

namespace ionpot::widget {
	class Box {
	public:
		Box(util::Size = {}, util::Point pos = {});

		bool contains(util::Point, util::Point offset = {}) const;

		util::Point max_point() const;

		void position(util::Point);
		util::Point position() const;

		util::Size size() const;

		void add_x(int amount);
		void add_y(int amount);

		void center_to(const Box&);

		void place_after(const Box&, int spacing = 0);
		void place_below(const Box&, int spacing = 0);
		void place_on(const Box&);

	protected:
		void size(util::Size);

	private:
		util::Point m_position;
		util::Size m_size;
	};

	util::Point min_point(const std::vector<const Box*>&);
	util::Point max_point(const std::vector<const Box*>&);

	template<class T>
	util::Size
	sum_sizes(const std::vector<T>& input)
	{
		return sum_sizes<const Box*>(util::ptr_vector<const Box>(input));
	}

	template<>
	util::Size sum_sizes(const std::vector<const Box*>&);
}
