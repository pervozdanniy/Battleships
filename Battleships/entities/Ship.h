#ifndef SHIP_H
#define SHIP_H

// class Board;
struct Coord;
class Board;

#include <vector>

class Ship {
	std::vector<Coord> shape;
	Board& board;
	const std::vector<Coord> getOccupied();
public:
	Ship(Board& board, std::vector<Coord> shape);
	~Ship();

	unsigned int size();

	bool isDead();


	void sink();
};

#endif // !SHIP_H
