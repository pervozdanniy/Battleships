#ifndef BOARD_H
#define BOARD_H


struct Coord;
// struct Field;

#include "Field.h"

const unsigned int SIZE = 10;
const unsigned int SHIPS_NUM = 1 + 2 + 3 + 4;

class Board {
	Field fields[SIZE][SIZE];
public:
	Board();

	bool hit(unsigned int x, unsigned int y);

	bool hit(Coord coord);

	Field& getField(unsigned int x, unsigned int y);

	Field& getField(Coord coord);
};

#endif // !BOARD_H