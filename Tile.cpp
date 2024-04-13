#include "Tile.h"

#include <cassert>
#include <string>

Tile::Tile(int index):
	m_index{index}
{
	assert(index >= 0 && index <= 15 && "Value should be between 0 and 15");
}

int Tile::getNum() const
{
	return m_index;
}


bool Tile::isEmpty() const
{
	return m_index == 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	if (tile.m_index <= 9) {
		out << "  " << (tile.isEmpty() ? " " : std::to_string(tile.m_index)) << " ";
		
	}
	else {
		out << " " << tile.m_index << " ";
	}
	
	return out;
}
