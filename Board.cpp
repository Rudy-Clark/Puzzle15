#include "Board.h"
#include "Random.h"

#include <utility>
#include <cassert>

Board::Board()
{
	// initializing board
	static constexpr int len{ Settings::SIZE };
	int acc{ 1 };
	for (size_t row{}; row < len; ++row) {
		for (size_t col{}; col < len; ++col) {
			m_tiles[row][col] = Tile{ acc % 16 };
			// increment 
			++acc;
		}
	}
}

void Board::moveTile(const Direction& dir)
{
	Point emptyTile{ getTilePos() };
	Point adj{ emptyTile.getAdjacentPoint(-dir) };

	if (isValidTilePos(adj)) {
		std::swap(m_tiles[emptyTile.y][emptyTile.x], m_tiles[adj.y][adj.x]);
	}
}

Point Board::getTilePos()
{
	const size_t len{ m_tiles.size() };
	for (size_t row{}; row < len; ++row) {
		for (size_t col{}; col < len; ++col) {
			// let's find empty tile to see offsets
			if (m_tiles[row][col].getNum() == 0) {
				return { static_cast<int>(col), static_cast<int>(row) };
			}
		}
	}

	assert(0 && "Empty tile not found!");
	return { -1, -1 };
}

bool Board::isValidTilePos(const Point& p)
{
	return ((p.x < Settings::SIZE && p.x >= 0) && (p.y < Settings::SIZE && p.y >= 0));
}

void Board::randomize()
{
	for (size_t i{}; i < Settings::randomIteration; ++i) {
		Point tilePos{ getTilePos() };
		Point randomAdj{ tilePos.getAdjacentPoint(Direction::getRandomDir()) };
		if (isValidTilePos(randomAdj)) {
			std::swap(m_tiles[tilePos.y][tilePos.x], m_tiles[randomAdj.y][randomAdj.x]);
		}
	}
}

bool operator==(const Board& b1, const Board& b2)
{
	static constexpr size_t len{ Settings::SIZE };
	for (size_t row{}; row < len; ++row) {
		for (size_t col{}; col < len; ++col) {
			if (b1.m_tiles[row][col].getNum() != b2.m_tiles[row][col].getNum()) return false;
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	static constexpr int len{ Settings::SIZE };

	for (int row{}; row < Settings::g_consoleLines; ++row) {
		out << "\n";
	}

	for (size_t row{}; row < len; ++row) {
		for (size_t col{}; col < len; ++col) {
			out << b.m_tiles[row][col];
		}
		out << "\n";
	}

	return out;
}
