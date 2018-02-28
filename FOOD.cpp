#include "FOOD.h"

FOOD::FOOD()
{
	srand(time(NULL));
	x = 5;
	y = 5;
	gotoXY(x, y);
	cout << "*";
}

void FOOD::give(int map[100][100], int &score)
{
	if (map[x][y] != 5) return;
	score++;
	x = rand() % 13 + 1;
	y = rand() % 23 + 1;
	while (map[x][y] == 5 && x>13 && y>13)
	{
		x = rand() % 13 + 1;
		y = rand() % 23 + 1;
	}
	gotoXY(x, y);
	cout << "*";
}

FOOD::~FOOD()
{
}
