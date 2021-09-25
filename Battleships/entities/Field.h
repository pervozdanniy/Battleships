#ifndef FIELD_H
#define FIELD_H

class Ship;

#include <optional>
#include "Ship.h"

enum class Types : short {
	water = 0,
	ship = 1,
};

struct Field {
	int x;
	int y;
	bool isHit;
	Types type;
	std::optional<Ship*> ship;

	Field() {
		x = 0;
		y = 0;
		isHit = false;
		type = Types::water;
	};
	Field(unsigned int x, unsigned int y) : x(x), y(y), isHit(false), type(Types::water) {};
	Field(unsigned int x, unsigned int y, Ship* ship) : x(x), y(y), isHit(false), ship(ship) {
		if (ship) {
			type = Types::ship;
		}
	};

	bool hit()
	{
		if (isHit) {
			return false;
		}
		isHit = true;
		if (ship) {
			auto value = ship.value();
			if (value->isDead()) {
				value->sink();
			}
			return true;
		}

		return false;
	};

	friend bool operator <(const Field& l, const Field& r)
	{
		if (l.x < r.x || (l.x == r.x && l.y < r.y)) {
			return true;
		}

		return false;
	}
};

#endif // !FIELD_H