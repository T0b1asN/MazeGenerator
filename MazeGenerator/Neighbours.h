#pragma once
#include "curr.h"
#include "Cell.h"
#include <VECTOR>

class Neighbours
{
private:
	Cell _left;
	Cell _top;
	Cell _right;
	Cell _down;

public:
	Neighbours();
	~Neighbours();

	void left(Cell p) { _left = p; }
	Cell left() { return _left; }

	void top(Cell p) { _top = p; }
	Cell top() { return _top; }

	void right(Cell p) { _right = p; }
	Cell right() { return _right; }

	void down(Cell p) { _down = p; }
	Cell down() { return _down; }

	std::vector<Cell> validCells();
};

