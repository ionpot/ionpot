#pragma once

#include "grid.hpp"
#include "hexagon.hpp"
#include "point.hpp"
#include "size.hpp"

namespace ionpot::util {
	struct HexGrid {
		Hexagon hex;

		HexGrid(Hexagon);

		bool contains(Point, GridIndex) const;

		GridIndex get_visible_index(Point) const;
		int get_visible_column(int x_pos) const;
		int get_visible_row(int y_pos) const;

		GridSize max_visible(Size) const;
		int max_visible_columns(int size) const;
		int max_visible_rows(int size) const;

		Point position_of(GridIndex) const;
		int x_of(GridIndex) const;
		int y_of(GridIndex) const;

		Size size_of(GridSize) const;

		static Size calculate_size(const Hexagon&, GridSize);
		static int calculate_height(const Hexagon&, GridSize);
		static int calculate_width(const Hexagon&, GridSize);
	};
}
