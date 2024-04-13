#include "Point.h"

Point Point::getAdjacentPoint(const Direction& dir) const
{
    switch (dir.getType()) {
        case Direction::up: {
            return { x, y - 1 };
        }
        case Direction::down: {
            return { x, y + 1 };
        }
        // changed sign from original -
        case Direction::left: {
            return { x - 1, y };
        }
        // changed sign from original -
        case Direction::right: {
            return { x + 1, y };
        }
    }

    return *this;
}

bool Point::operator==(const Point& other)
{
    return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other)
{
    return !((*this) == other);
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.x << ", " << p.y << ")\n";

    return out;
}

