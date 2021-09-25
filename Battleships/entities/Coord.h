#ifndef COORD_H
#define COORD_H

#include <stdlib.h>

struct Coord
{
	int x;
	int y;

	Coord() : x(0), y(0) {};
	Coord(unsigned int x, unsigned int y) : x(x), y(y) {};
	Coord(const Coord& coord) { x = coord.x; y = coord.y; }

	bool isNeigbour(Coord coord) {
		return (coord.x == x && abs(coord.y - y) == 1) || (coord.y == y && abs(coord.x - x) == 1);
	};

	bool touchesCorner(Coord coord) {
		return abs(coord.x - x) == 1 && abs(coord.y - y) == 1;
	};

	std::vector<Coord> getNeigbours() const
	{
		std::vector<Coord> neighbours;
		if (y > 0) {
			const int newY = y - 1;
			neighbours.push_back(Coord(x, newY));
			addHorizontalNeighbours(newY, neighbours);
		}
		if (y < 9) {
			const int newY = y + 1;
			neighbours.push_back(Coord(x, newY));
			addHorizontalNeighbours(newY, neighbours);
		}
		addHorizontalNeighbours(y, neighbours);

		return neighbours;
	}

private:
	void addHorizontalNeighbours(int y, std::vector<Coord>& neighbours) const {
		if (x > 0) {
			neighbours.push_back(Coord(x - 1, y));
		}
		if (x < 9) {
			neighbours.push_back(Coord(x + 1, y));
		}
	}
};

#endif // !COORD_H