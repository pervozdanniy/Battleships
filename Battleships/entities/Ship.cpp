#include "Ship.h"

#include <iostream>
#include "Board.h"
#include "Field.h"
#include "Coord.h"

Ship::Ship(Board& board, std::vector<Coord> shape) : board(board), shape(shape) {
	for (const Coord& coord : getOccupied())
	{
		Field& field = board.getField(coord);
		field.ship = this;
	}
	for (const Coord& coord : shape)
	{
		Field& field = board.getField(coord);
		field.ship == this;
		field.type = Types::ship;

	}
};

Ship::~Ship() {};

unsigned int Ship::size()
{
	return shape.size();
};

bool Ship::isDead()
{
	bool res = true;
	for (const Coord& coord : shape)
	{
		Field& field = board.getField(coord);
		if (!field.isHit) {
			res = false;
			break;
		}
	}

	return res;
};

void Ship::sink()
{
	for (const Coord& coord : getOccupied()) {
		Field& field = board.getField(coord);
		field.isHit = true;
	}
};

const std::vector<Coord> Ship::getOccupied()
{
	std::vector<Coord> res;

	for (const Coord& coord : shape)
	{
		auto vector = coord.getNeigbours();
		res.insert(res.end(), vector.begin(), vector.end());
	}

	return res;
};