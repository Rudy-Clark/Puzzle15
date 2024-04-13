#pragma once
#include <array>

namespace Settings {
	static constexpr int randomIteration{ 1000 };
	static constexpr int SIZE{ 4 };
	static constexpr int g_consoleLines{ 25 };
	// Direction::Type orders must match
	static constexpr std::array validCommands{ 'w', 's', 'd', 'a', 'q' };
}
