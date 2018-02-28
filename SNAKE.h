#pragma once

#include "gamePlay.h"

struct NODE
{
	int x, y;
	NODE *next;
	NODE *back;
};

class SNAKE
{
public:
	SNAKE();
	void display(int map[100][100], int m, int n);
	void move(int map[100][100], int m, int n);
	void hide(int map[100][100], int m, int n);
	void extend();
	void setDirection(int n);
	bool check(int map[100][100], int m, int n);
	virtual ~SNAKE();
private:
	NODE *head;
	NODE *tail;
	int direction;
};

