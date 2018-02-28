#include "SNAKE.h"

SNAKE::SNAKE()
{
	head = new NODE();
	tail = new NODE();
	NODE *body = new NODE();

	head->x = 3;
	head->y = 1;
	body->x = 2;
	body->y = 1;
	tail->x = 1;
	tail->y = 1;
	
	head->next = body;
	body->next = tail;
	tail->next = NULL;

	tail->back = body;
	body->back = head;
	head->back = NULL;

	direction = 3;
}

void SNAKE::display(int map[100][100], int m, int n)
{
	/*NODE *node = head;
	while (node != NULL)
	{
		int x, y;
		x = node->x;
		y = node->y;
		map[x][y] = 5;
		gotoXY(x, y);
		cout << "0";
		node = node->next;
	}*/
	map[head->x][head->y] = 5;
	gotoXY(head->x, head->y);
	cout << "0";
}

void SNAKE::hide(int map[100][100], int m, int n)
{
	/*NODE *node = head;
	while (node != NULL)
	{
		int x, y;
		x = node->x;
		y = node->y;
		map[x][y] = 0;
		gotoXY(x, y);
		cout << " ";
		node = node->next;
	}*/
	map[tail->x][tail->y] = 0;
	gotoXY(tail->x, tail->y);
	cout << " ";
}

void SNAKE::extend()
{
	NODE *node = new NODE;
	node->x = tail->x;
	node->y = tail->y;
	node->next = NULL;
	node->back = tail;
	tail->next = node;
	tail = node;
}

void swapTail(NODE *&head, NODE *&tail)
{
	int x = head->x;
	int y = head->y;

	NODE *tmp = tail;
	tmp->x = x;
	tmp->y = y;

	tail = tail->back;

	tmp->back = NULL;
	tail->next = NULL;
	tmp->next = head->next;
	head->next->back = tmp;
	head->next = tmp;
	tmp->back = head;
}

void SNAKE::move(int map[100][100], int m, int n)
{
	swapTail(head, tail);
	switch (direction)
	{
	case 1: head->x--; break;
	case 2: head->y++; break;
	case 3: head->x++; break;
	case 4: head->y--; break;
	}
}

void SNAKE::setDirection(int n)
{
	if (abs(n - direction) != 2) direction = n;
}

bool SNAKE::check(int map[100][100], int m, int n)
{
	if (map[head->x][head->y] != 0) return false;
	return true;
}

SNAKE::~SNAKE()
{
	NODE *tmp = new NODE();
	int x = 0;
	while (head->next != NULL)
	{
		x++;
		tmp = head->next;
		tmp->back = NULL;
		head->next = NULL;
		free(head);
		head = tmp;
	}
	free(head);
}
