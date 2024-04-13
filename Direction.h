#pragma once
#include <string>
#include <ostream>

using namespace std::string_view_literals;

class Direction
{
public:
	// see Settings::validCommands order
	enum Type {
		up,
		down,
		right,
		left,
		max_directions
	};

	Direction(Type t);

	Type getType() const;

	static Direction getRandomDir();

	friend std::ostream& operator<<(std::ostream& out,const Direction& dir);

	Direction operator-() const;

private:
	Type m_type{};
	static constexpr std::string_view m_dirNames[max_directions]{ "up"sv, "down"sv, "right"sv, "left"sv };
};

