#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>

#define rInt(min, max) min + (rand() % (int)(max - min + 1))

namespace cr
{
	sf::RenderWindow& currWin();

	int getCols();
	void setCols(int _cols);
	int getRows();
	void setRows(int _rows);
}
