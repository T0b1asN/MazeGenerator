#include "Map.h"

Map::Map(sf::Vector2i _startPoint) : 
	startPoint(_startPoint),
	curr(startPoint, true)
{
	std::cout << "Cols: " << cr::getCols() << "|| Rows: " << cr::getRows() << std::endl;
	for (int x = 0; x < cr::getCols(); x++)
	{
		std::vector<Cell> temp;
		for (int y = 0; y < cr::getRows(); y++)
		{
			if (sf::Vector2i(x, y) == startPoint)
				temp.push_back(Cell(sf::Vector2i(x, y), true));
			else
				temp.push_back(Cell(sf::Vector2i(x, y), false));
		}
		_cells.push_back(temp);
	}
}

Map::~Map()
{

}

void Map::Draw()
{
	for (std::vector<Cell> vec : _cells)
	{
		for (Cell c : vec)
		{
			c.Draw();
		}
	}
}

std::vector<Cell> Map::getUnvisitedNBs(sf::Vector2i pos)
{
	std::vector<Cell> ret;
	if (pos.x > 1 && !_cells.at(pos.x - 2).at(pos.y).wasVisited())
	{
		ret.push_back(_cells.at(pos.x - 2).at(pos.y));
	}

	if (pos.y > 1 && !_cells.at(pos.x).at(pos.y - 2).wasVisited())
	{
		ret.push_back(_cells.at(pos.x).at(pos.y - 2));
	}

	if (pos.x < cr::getCols() - 2 && !_cells.at(pos.x + 2).at(pos.y).wasVisited())
	{
		ret.push_back(_cells.at(pos.x + 2).at(pos.y));
	}

	if (pos.y < cr::getRows() - 2 && !_cells.at(pos.x).at(pos.y + 2).wasVisited())
	{
		ret.push_back(_cells.at(pos.x).at(pos.y + 2));
	}

	return ret;
}

bool Map::hasUnivisitedTiles()
{
	bool ret;
	for (std::vector<Cell> vec : _cells)
	{
		for (Cell c : vec)
		{
			if (!c.wasVisited())
				ret = true;
		}
	}
	return ret;
}

void Map::GenerateMaze()
{

}

void Map::GenerationStep()
{
	std::vector<Cell> unvNBs = getUnvisitedNBs(curr.getPos());
	if (unvNBs.size() > 0)
	{
		stack.push_back(curr);

		int r = rand() % unvNBs.size();
		CellAt(unvNBs.at(r).getPos()).visit();

		int dX = unvNBs.at(r).getPos().x - curr.getPos().x;
		int dY = unvNBs.at(r).getPos().y - curr.getPos().y;

		if (dX > 0)
			CellAt(sf::Vector2i(curr.getPos().x + 1, curr.getPos().y)).visit();
		else if (dX < 0)
			CellAt(sf::Vector2i(curr.getPos().x - 1, curr.getPos().y)).visit();
		else if (dY > 0)
			CellAt(sf::Vector2i(curr.getPos().x, curr.getPos().y + 1)).visit();
		else if (dY < 0)
			CellAt(sf::Vector2i(curr.getPos().x, curr.getPos().y - 1)).visit();

		curr = unvNBs.at(r);
	}
	else
	{
		if (stack.size() > 0)
		{
			curr = stack.back();
			stack.pop_back();
		}
		else
			return;
	}
}
