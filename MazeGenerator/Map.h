#pragma once
#include "curr.h"
#include "Cell.h"
#include <VECTOR>

class Map
{
private:
	std::vector<std::vector<Cell>> _cells;

	sf::Vector2i startPoint;
public:
	Map(sf::Vector2i startPoint = sf::Vector2i(cr::getCols() / 2, cr::getRows() / 2));
	~Map();

	void Draw();

	void GenerateMaze();
	void GenerationStep();

	std::vector<std::vector<Cell>>& cells() { return _cells; }
};

