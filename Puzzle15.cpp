// Puzzle15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Rudy-Clark 
// License: MIT

#include <iostream>
#include <algorithm>
#include <array>
#include <cassert>

#include "Tile.h"
#include "Board.h"
#include "Settings.h"
#include "Direction.h"
#include "Point.h"

namespace UserInput {

    void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCommandFromUser() {
        char input{};
        std::cout << "Enter a command: ";
        while (true) {
            std::cin >> input;
            const auto result{ std::find(std::begin(Settings::validCommands), std::end(Settings::validCommands), input) };
            
            if (!std::cin) {
                ignoreLine();
                continue;
            };

            if (result != std::end(Settings::validCommands)) break;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return input;
    }

    Direction getDirFromChar(char c) {
        using namespace Settings;
        const auto& found{ std::find(validCommands.begin(), validCommands.end(), c) };
        auto targetIndex = found - validCommands.begin();
        return Direction{ (Direction::Type)targetIndex };
    }
}

int main()
{
    // step 1
    //Tile tile1{ 10 };
    //Tile tile2{ 8 };
    //Tile tile3{ 0 }; // the missing tile
    //Tile tile4{ 1 };

    //std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
    //std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

    //std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
    //std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';

    // step 2-3
    //Board board{};
    //std::cout << board;

    //for (int i{ 0 }; i < 4; ++i) {
    //    std::cout << "Generating random direction... " << Direction::getRandomDir() << '\n';
    //}

    //// check operator - unary
    //Direction dirUp{ Direction::up };
    //Direction dirDown{ -dirUp };
    //Direction dirLeft{ Direction::left };
    //Direction dirRight{ -dirLeft };

    //// should output down 
    //std::cout << '\n' << "Direction -operator(up): " << dirDown << "\n";
    //std::cout << "Direction -operator(left): " << dirRight << "\n\n";

    //while (true) {
    //    char c{ UserInput::getCommandFromUser() };

    //    if (c == 'q') {
    //        std::cout << "Bye-Bye!";
    //        break;
    //    }
    //    
    //    Direction dir{ UserInput::getDirFromChar(c) };
    //    std::cout << "You entered direction:  " << dir << "\n";
    //}
    // 
    // step 4
    /*std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up) == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down) == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left) == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';*/

    // step 5 move Board tile
    Board board{};
    board.randomize();

    std::cout << board;

    Board solvedBoard{};

    /*for (int i{ 0 }; i < 4; ++i) {
        std::cout << "Generating random direction... " << Direction::getRandomDir() << '\n';
    }*/

    while (true) {
        char c{ UserInput::getCommandFromUser() };

        if (c == 'q') {
            std::cout << "Bye-Bye!";
            break;
        }
        
        Direction dir{ UserInput::getDirFromChar(c) };
        std::cout << "You entered direction:  " << dir << "\n";
        
        board.moveTile(dir);

        // check if user win. Compare with solved board;
        if (board == solvedBoard) {
            std::cout << "You won!!!";
            break;
        }

        std::cout << board;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
