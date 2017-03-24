#include "Neighbours.h"



Neighbours::Neighbours():
	_left(sf::Vector2i(-1, -1)),
	_top(sf::Vector2i(-1, -1)),
	_right(sf::Vector2i(-1, -1)),
	_down(sf::Vector2i(-1, -1))
{
}


Neighbours::~Neighbours()
{
}

std::vector<Cell> Neighbours::validCells()
{
	std::vector<Cell> ret;
	if (_left.getPos() != sf::Vector2i(-1, -1))
		ret.push_back(_left);
	if (_top.getPos() != sf::Vector2i(-1, -1))
		ret.push_back(_top);
	if (_right.getPos() != sf::Vector2i(-1, -1))
		ret.push_back(_right);
	if (_down.getPos() != sf::Vector2i(-1, -1))
		ret.push_back(_down);
	return ret;
}
