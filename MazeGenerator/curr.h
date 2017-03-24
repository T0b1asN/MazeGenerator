#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>

#define rInt(min, max) min + (rand() % (int)(max - min + 1))
#define rFloat() (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))

#define HorBias 0.55f
#define VerBias 0.45f

#define Title "MazeGenerator"

namespace cr
{
	sf::RenderWindow& currWin();

	int getCols();
	void setCols(int _cols);
	int getRows();
	void setRows(int _rows);

	sf::Vector2u getTileSize();
}
