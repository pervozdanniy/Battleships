// Battleships.cpp: определяет точку входа для приложения.
//

#include "Battleships.h"

using namespace std;

void renderBoard(Board* board)
{
	for (int y = 0; y < SIZE; y++)
	{
		if (y == 0) {
			cout << endl << "+---+---+---+---+---+---+---+---+---+---+" << endl;
		}
		for (int x = 0; x < SIZE; x++)
		{
			char res;
			const Field& field = board->getField(x, y);
			if (field.isHit) {
				res = '*';
			}
			else if (field.type == Types::ship) {
				res = 'S';
			}
			else {
				res = ' ';
			}

			if (x == 0) {
				cout << "|";
			}
			cout << ' ' << res << " |";
			
		}
		cout << endl << "+---+---+---+---+---+---+---+---+---+---+" << endl;
	}
}

int main()
{
	Board* board = new Board();
	Player* player1 = new ConsolePlayer(*board);
	player1->placeShips();
	renderBoard(board);
	player1->nextTurn();

	board->hit(1, 1);
	board->hit(1, 3);
	if (board->hit(1, 2)) {
		cout << "IOA" << endl;
	}

	cout << "Hello CMake." << endl;
	return 0;
}
