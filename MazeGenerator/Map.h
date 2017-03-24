#pragma once
#include "curr.h"
#include "Cell.h"
#include "Neighbours.h"
#include <VECTOR>

class Map
{
private:
	std::vector<std::vector<Cell>> _cells;
	std::vector<Cell> stack;

	sf::Vector2i startPoint;

	std::vector<Cell> getUnvisitedNBs(sf::Vector2i pos);
	std::vector<Cell> getNBs(sf::Vector2i pos);
	Neighbours _getNBs(sf::Vector2i pos);
	bool hasUnivisitedTiles();

	Cell curr;

	bool finished = false;
public:
	Map(sf::Vector2i startPoint = sf::Vector2i(cr::getCols() / 2, cr::getRows() / 2));
	~Map();

	void Draw();

	bool isFinished() { return finished; }

	Cell& CellAt(sf::Vector2i pos) { return _cells.at(pos.x).at(pos.y); }

	void GenerateMaze();
	void GenerateMaze_Bias();
	void GenerationStep();
	void GenerationStep_Bias(float horBias = HorBias, float verBias = VerBias);

	std::vector<std::vector<Cell>>& cells() { return _cells; }
};

