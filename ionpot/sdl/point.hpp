#pragma once

#include <util/size.hpp>

#include <SDL.h>

#include <string>

namespace ionpot::sdl {
	struct Point {
		int x {0};
		int y {0};

		Point() = default;
		Point(int x_and_y);
		Point(int x, int y);
		Point(const util::Size&);

		void clear();

		double distance(Point target) const;

		Point negate() const;

		void pick_min(const Point& p);
		void pick_max(const Point& p);

		SDL_Point to_sdl() const;
		util::Size to_size() const;

		Point operator+(int) const;
		Point operator+(const Point& p) const;
		Point operator-(const Point& p) const;
		Point operator*(int) const;
		Point operator++(int);
		Point& operator+=(const Point& p);
		Point& operator-=(const Point& p);
		bool operator==(const Point& p) const;
		bool operator!=(const Point& p) const;

		std::string to_str() const;

		static const Point one;

		static Point min(Point a, Point b = {0, 0});
		static Point max(Point a, Point b = {0, 0});
	};
}
