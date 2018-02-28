#include "gamePlay.h"
#include <fstream>

char pixel(int n)
{
	switch (n)
	{
	case 1: return '-';
	case 2: return '|';
	case 3: return '+';
	case 0: return ' ';
	case 10: return '*';
	}
}

void displayMap(int map[100][100], int m, int n, int bestScore)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) cout << pixel(map[i][j]);
		cout << endl;
	}
	gotoXY(12, 6);
	cout << "BEST SCORE: " << bestScore;
}

void init(int map[100][100], int &m, int &n, int &bestScore)
{
	fstream input("MAP.INP", ios::in);
	input >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) input >> map[i][j];
	displayMap(map, m, n, bestScore);
	input.close();
	input.open("DATA.INP", ios::in);
	input >> bestScore;
	input.close();
}

void gotoXY(int x, int y)
{
	COORD cursor;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	swap(x, y);
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(console, cursor);
}

int showMenu(int bestScore)
{
	gotoXY(2, 7);
	cout << "SNAKE GAME" << endl << endl;
	gotoXY(4, 4);
	cout << "( ) Start" << endl;
	gotoXY(5, 4);
	cout << "( ) Instruction" << endl;
	gotoXY(6, 4);
	cout << "( ) Quit" << endl;

	gotoXY(12, 6);
	cout << "BEST SCORE: " << bestScore;

	int x = 4, y = 5;
	
	while (1)
	{
		gotoXY(x, y);
		cout << "*";
		char c = 0;
		if (_kbhit)
		{
			c = _getch();
			gotoXY(x, y);
			cout << " ";
		}
		switch (c)
		{
		case 80: if (x <= 5) x++; break;
		case 72: if (x >= 5) x--; break;
		case 13: return x;
		}
	}
}

void clearScr()
{
	for(int i=1; i<=13; i++)
		for (int j = 1; j <= 23; j++)
		{
			gotoXY(i, j);
			cout << " ";
		}
}

bool control(SNAKE &snake, DWORD n)
{
	for (int i = 1; i <= n; i++)
	{
		Sleep(1);
		if (_kbhit())
		{
			char c = _getch();
			switch (c)
			{
			case 72: snake.setDirection(1); return true;;
			case 77: snake.setDirection(2); return true;
			case 80: snake.setDirection(3); return true;
			case 75: snake.setDirection(4); return true;
			case 13: return false;
			}
		}
	}
	return true;
}

void writeScore(int score)
{
	gotoXY(0, 33);
	cout << score;
}

void gameOver(int score, int &bestScore)
{
	if (score > bestScore) bestScore = score;
	clearScr();
	gotoXY(2, 7);
	cout << "GAME OVER";
	gotoXY(3, 6);
	cout << "YOUR SCORE";
	gotoXY(4, 10);
	cout << score;
	gotoXY(5, 6);
	cout << "BEST SCORE";
	gotoXY(6, 10);
	cout << bestScore;
	_getch();
	Sleep(500);
	system("cls");
}

void writeBestScore(int bestScore)
{
	fstream output("DATA.INP", ios::out);
	output << bestScore;
	output.close();
}

void play(int map[100][100], int m, int n, int &bestScore)
{
	SNAKE snake;
	FOOD food;
	bool c = true;
	int score = 0;
	gotoXY(0, 26);
	cout << "SCORE: ";
	while (c)
	{
		if (!snake.check(map, m, n))
		{
			gameOver(score, bestScore);
			writeBestScore(bestScore);
			displayMap(map, m, n, bestScore);
			break;
		}
		snake.display(map, m, n);
		int tmp = score;
		food.give(map,score);
		if (score > tmp) snake.extend();
		writeScore(score);
		c = control(snake, 100);
		snake.hide(map, m, n);
		snake.move(map, m, n);
	}
}