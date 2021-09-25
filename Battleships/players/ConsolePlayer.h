#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include <iostream>
#include "../Player.h"
#include "../entities/Coord.h"
#include "../entities/Field.h"


class ConsolePlayer : public Player
{
	Coord getCoord()
	{
		int row, col;
		std::string error;
		do {
			if (!error.empty()) {
				std::cout << error << std::endl;
			}
			std::cout << "Enter row: " << std::endl;
			std::cin >> row;
			std::cout << "Enter column: " << std::endl;
			std::cin >> col;
		} while (!validate(row, col, error));
		
		return Coord(row, col);
	};

	bool validate(int x, int y,  std::string& message)
	{
		bool res = true;

		do {
			if (x < 0) {
				res = false;
				message = "X underflow!";
				break;
			}
			if (y < 0) {
				res = false;
				message = "Y underflow!";
				break;
			}
			if (x > 9) {
				res = false;
				message = "X overflow!";
				break;
			}
			if (y > 9) {
				res = false;
				message = "Y overflow!";
				break;
			}
		} while (0);

		return res;
	}

public:
	ConsolePlayer(Board& board) : Player(board) {};

	Coord nextTurn()
	{
		return getCoord();
	};

protected:
	std::vector<Coord> nextShip(unsigned int size)
	{
		std::vector<Coord> shape;
		while (shape.size() < size)
		{
			Coord coord = getCoord();
			const Field& field = board.getField(coord);
			if (field.type == Types::water && !field.ship) {
				if (shape.empty()) {
					shape.push_back(coord);
				}
				else if (shape.back().isNeigbour(coord)) {
					shape.push_back(coord);
				}
				else {
					std::cout << "Enter valid coords: " << std::endl;
				}
			}
			else {
				std::cout << "Field x=" << coord.x << " y=" << coord.y << " already belongs to another ship!" << std::endl;
			}
			
		}

		return shape;
	}
};

#endif // !CONSOLE_PLAYER_H