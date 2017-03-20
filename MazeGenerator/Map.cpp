#include "Map.h"

Map::Map(sf::Vector2i _startPoint) : 
	startPoint(_startPoint)
{
	std::cout << "Cols: " << cr::getCols() << "|| Rows: " << cr::getRows() << std::endl;
	for (int x = 0; x < cr::getCols(); x++)
	{
		std::vector<Cell> temp;
		for (int y = 0; y < cr::getRows(); y++)
		{
			temp.push_back(Cell(sf::Vector2i(x, y)));
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
