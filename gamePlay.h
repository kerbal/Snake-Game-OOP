#ifndef _gamePlay_
#define _gamePlay_

#include "mainLib.h"

void init(int map[100][100], int &m, int &n, int &bestScore);
int showMenu(int bestScore);
void gotoXY(int x, int y);
void clearScr();
void play(int map[100][100], int m, int n, int &bestScore);

#endif // !_gamePlay_
