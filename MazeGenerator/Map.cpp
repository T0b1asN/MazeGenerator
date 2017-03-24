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

std::vector<Cell> Map::getNBs(sf::Vector2i pos)
{
	std::vector<Cell> ret;
	//links
	if (pos.x > 1)
	{
		ret.push_back(_cells.at(pos.x - 2).at(pos.y));
	}
	//oben
	if (pos.y > 1)
	{
		ret.push_back(_cells.at(pos.x).at(pos.y - 2));
	}
	//rechts
	if (pos.x < cr::getCols() - 2)
	{
		ret.push_back(_cells.at(pos.x + 2).at(pos.y));
	}
	//unten
	if (pos.y < cr::getRows() - 2)
	{
		ret.push_back(_cells.at(pos.x).at(pos.y + 2));
	}

	return ret;
}

Neighbours Map::_getNBs(sf::Vector2i pos)
{
	Neighbours ret;
	//links
	if (pos.x > 1)
	{
		ret.left(_cells.at(pos.x - 2).at(pos.y));
	}
	//oben
	if (pos.y > 1)
	{
		ret.top(_cells.at(pos.x).at(pos.y - 2));
	}
	//rechts
	if (pos.x < cr::getCols() - 2)
	{
		ret.right(_cells.at(pos.x + 2).at(pos.y));
	}
	//unten
	if (pos.y < cr::getRows() - 2)
	{
		ret.down(_cells.at(pos.x).at(pos.y + 2));
	}

	//std::cout << "pos down: " << ret.left().getPos().x << "|" << ret.left().getPos().y << std::endl;

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
	while (!finished)
		GenerationStep();
}

void Map::GenerateMaze_Bias()
{
	while (!finished)
		GenerationStep_Bias();
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
			finished = true;
	}
}

void Map::GenerationStep_Bias(float horBias, float verBias)
{
	Neighbours nbs = _getNBs(curr.getPos());

	int count = 0;
	for (Cell c : nbs.validCells())
		if (!CellAt(c.getPos()).wasVisited())
			count++;
	
	if (count > 0)
	{
		stack.push_back(curr);
		Cell chosen(sf::Vector2i(-1, -1));
		if (count > 1)
		{
			bool valid = false;
			while (!valid)
			{
				float rD = rFloat();

				if (rD < horBias / 2.f)
				{
					if (nbs.left().getPos() != sf::Vector2i(-1, -1))
						chosen = nbs.left();
				}
				else if (rD < horBias / 2.f + verBias / 2.f)
				{
					if (nbs.top().getPos() != sf::Vector2i(-1, -1))
						chosen = nbs.top();
				}
				else if (rD < 2 * horBias / 2.f + verBias / 2.f)
				{
					if (nbs.right().getPos() != sf::Vector2i(-1, -1))
						chosen = nbs.right();
				}
				else
				{
					if (nbs.down().getPos() != sf::Vector2i(-1, -1))
						chosen = nbs.down();
				}

				if (chosen.getPos() != sf::Vector2i(-1, -1) && !CellAt(chosen.getPos()).wasVisited())
				{
					valid = true;
					CellAt(chosen.getPos()).visit();
				}
			}

		}
		else if (count == 1)
		{
			for (Cell c : nbs.validCells())
				if (!CellAt(c.getPos()).wasVisited())
					chosen = CellAt(c.getPos());

			if (!CellAt(chosen.getPos()).wasVisited())
				CellAt(chosen.getPos()).visit();
		}

		if (chosen.getPos() == nbs.left().getPos())
			CellAt(sf::Vector2i(curr.getPos().x - 1, curr.getPos().y)).visit();
		else if (chosen.getPos() == nbs.top().getPos())
			CellAt(sf::Vector2i(curr.getPos().x, curr.getPos().y - 1)).visit();
		else if (chosen.getPos() == nbs.right().getPos())
			CellAt(sf::Vector2i(curr.getPos().x + 1, curr.getPos().y)).visit();
		else if (chosen.getPos() == nbs.down().getPos())
			CellAt(sf::Vector2i(curr.getPos().x, curr.getPos().y + 1)).visit();

		curr = CellAt(chosen.getPos());
	}
	else
	{
		if (stack.size() > 0)
		{
			curr = stack.back();
			stack.pop_back();
		}
		else
		{
			finished = true;
			std::cout << "Finished!" << std::endl;
		}
	}
}
