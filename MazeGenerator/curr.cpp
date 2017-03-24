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

sf::Vector2u size (-1.f, -1.f);
sf::Vector2u cr::getTileSize()
{
	if (size == sf::Vector2u(-1U, -1U))
		return win.getSize();
	else
		return sf::Vector2u(1, 1);
}
