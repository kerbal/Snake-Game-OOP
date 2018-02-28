#include "mainLib.h"

int map[100][100], n, m, choose,bestScore;
COORD cursor;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
PCURSORINFO pt;
CONSOLE_CURSOR_INFO cursorInfor;

int main()
{
	cursorInfor.bVisible = false;
	cursorInfor.dwSize = 10;
	SetConsoleCursorInfo(console, &cursorInfor);
	init(map, m, n, bestScore);
	while (choose != 3)
	{
		choose = showMenu(bestScore) - 3;
		switch (choose)
		{
		case 1:
			clearScr();
			play(map, m, n, bestScore);
			clearScr();
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (map[i][j] == 5) map[i][j] = 0;
			break;
		case 2:
			break;
		}
	}
	gotoXY(13, 7);
	cout << "QUITTING...";
	Sleep(1000);
	return 0;
}