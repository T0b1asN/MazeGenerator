#pragma once
#include "curr.h"

class Cell
{
private:
	sf::Vector2i pos;
	sf::Vector2f size;

	bool visited;

	sf::RectangleShape body;
public:
	Cell(sf::Vector2i _pos, bool _visited = false);
	~Cell();

	bool wasVisited() { return visited; }
	void visit();		// { visited = true; }

	sf::Vector2i getPos() { return pos; }

	void setCol(sf::Color _color) { body.setFillColor(_color); }

	void Draw();
};

