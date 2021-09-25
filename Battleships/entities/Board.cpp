#include "Board.h"
#include "Field.h"
#include "Coord.h"

Board::Board()
{
	for (unsigned int i = 0; i < SIZE; i++)
	{
		for (unsigned int j = 0; j < SIZE; j++)
		{
			fields[i][j] = Field(i, j);
		}
	}
};

bool Board::hit(unsigned int x, unsigned int y)
{
	return fields[x][y].hit();
};

bool Board::hit(Coord coord)
{
	return fields[coord.x][coord.y].hit();
};

Field& Board::getField(unsigned int x, unsigned int y)
{
	return fields[x][y];
};

Field& Board::getField(Coord coord)
{
	return fields[coord.x][coord.y];
};
