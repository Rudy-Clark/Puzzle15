#pragma once
#include "Direction.h"

struct Point {
	int x{};
	int y{};

	Point getAdjacentPoint(const Direction& dir) const;

	bool operator==(const Point& other);
	bool operator!=(const Point& other);

	friend std::ostream& operator<<(std::ostream& out, const Point& p);
};