#include "curr.h"

sf::RenderWindow win;

sf::RenderWindow& cr::currWin()
{
	return win;
}

int cols, rows;

int cr::getCols()
{
	return cols;
}

void cr::setCols(int _cols)
{
	cols = _cols;
}

int cr::getRows()
{
	return rows;
}

void cr::setRows(int _rows)
{
	rows = _rows;
}