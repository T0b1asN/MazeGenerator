#include "Cell.h"

Cell::Cell(sf::Vector2i _pos, bool _visited) :
	pos(_pos), 
	size(sf::Vector2f(cr::currWin().getSize().x / cr::getCols(), cr::currWin().getSize().y / cr::getRows())),
	visited(_visited)
{	
	body = sf::RectangleShape(size);
	if (!visited)
		body.setFillColor(sf::Color::Black);
	else
		body.setFillColor(sf::Color::White);

	body.setPosition(sf::Vector2f(size.x * (float)pos.x, size.y * (float)pos.y));
}

Cell::~Cell()
{

}

void Cell::Draw()
{
	cr::currWin().draw(body);
}

void Cell::visit()
{
	visited = true;
	body.setFillColor(sf::Color::White);
}
