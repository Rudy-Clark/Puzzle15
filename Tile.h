#pragma once
#include <iostream>

class Tile
{
public:
	Tile(int index = 0);

	int getNum() const;
	bool isEmpty() const;

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);



private:
	int m_index{};
};

