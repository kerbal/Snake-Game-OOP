#pragma once

#include "mainLib.h"

class FOOD
{
public:
	FOOD();
	void give(int map[100][100], int &score);
	virtual ~FOOD();
private:
	int x, y;
};