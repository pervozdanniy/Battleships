#ifndef PLAYER_H
#define PLAYER_H

#include "entities/Ship.h"
#include "entities/Coord.h"

class Board;

#include <vector>

class Player
{
protected:
	Board& board;

	std::vector<Ship*> ships;

	virtual std::vector<Coord> nextShip(unsigned int size) = 0;

public:
	Player(Board& board);

	virtual Coord nextTurn() = 0;

	void placeShips();
};

#endif // PLAYER_H