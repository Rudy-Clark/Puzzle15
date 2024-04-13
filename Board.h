#pragma once
#include "Tile.h"
#include "Settings.h"
#include "Direction.h"
#include "Point.h"

#include <array>
#include <iostream>

class Board
{
public:
	Board();

	void moveTile(const Direction& dir);
	Point getTilePos();
	static bool isValidTilePos(const Point& p);
	void randomize();

	friend bool operator==(const Board& b1, const Board& b2);
	friend std::ostream& operator<<(std::ostream& out, const Board& b);

private:
	std::array<std::array<Tile, Settings::SIZE>, Settings::SIZE> m_tiles{};
};

