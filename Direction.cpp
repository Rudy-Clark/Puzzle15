#include "Direction.h"
#include "Random.h"
#include <cassert>

Direction::Direction(Type t):
	m_type{ t }
{
	assert(static_cast<int>(t) < static_cast<int>(Direction::Type::max_directions) && "We have only 4 direction types");
}

Direction::Type Direction::getType() const
{
	return m_type;
}

Direction Direction::getRandomDir()
{
	Type randomType{ (Type)(Random::get(0, Direction::max_directions - 1)) };
	return Direction{ randomType };
}

Direction Direction::operator-() const
{
	int tInt{ m_type };
	int invT{ tInt % 2 == 1 ? tInt - 1 : tInt + 1 };

	return Direction { (Type)invT };
}

std::ostream& operator<<(std::ostream& out, const Direction& dir)
{
	out << dir.m_dirNames[static_cast<int>(dir.m_type)];

	return out;
}
