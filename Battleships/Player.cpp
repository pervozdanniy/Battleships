#include "Player.h"
#include "entities/Board.h"
#include "entities/Ship.h"

Player::Player(Board& board) : board(board) {};

void Player::placeShips()
{
	for (int i = 0; i < 2; i++)
	{
		const auto shape = nextShip(1);
		Ship* ship = new Ship(board, shape);
		ships.push_back(ship);
	}
	/**
	for (int i = 0; i < 3; i++)
	{
		const auto shape = nextShip(2);
		ships.push_back(new Ship(board, shape));
	}
	for (int i = 0; i < 2; i++)
	{
		const auto shape = nextShip(3);
		ships.push_back(new Ship(board, shape));
	}
	*/
	//const auto shape = nextShip(4);
	//ships.push_back(new Ship(board, shape));
}
