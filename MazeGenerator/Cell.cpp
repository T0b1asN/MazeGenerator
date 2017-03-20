#include "Cell.h"

Cell::Cell(sf::Vector2i _pos) :
	pos(_pos), 
	size(sf::Vector2f(cr::currWin().getSize().x / cr::getCols(), cr::currWin().getSize().y / cr::getRows()))
{
	debCol = sf::Color(rInt(0, 255), rInt(0, 255), rInt(0, 255));
}

Cell::~Cell()
{

}

void Cell::Draw()
{
	sf::RectangleShape body(size);
	body.setPosition(sf::Vector2f(size.x * (float)pos.x, size.y * (float)pos.y));
	body.setFillColor(debCol);
	cr::currWin().draw(body);
}
