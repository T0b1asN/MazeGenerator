#pragma once
#include "curr.h"

class Cell
{
private:
	sf::Vector2i pos;
	sf::Vector2f size;

	bool visited;

	sf::Color debCol;
public:
	Cell(sf::Vector2i _pos);
	~Cell();

	bool wasVisited() { return visited; }
	void visit() { visited = true; }

	void Draw();
};

