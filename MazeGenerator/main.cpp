#include "curr.h"
#include "Map.h"

//Start and end chosen after generation (from top/bottom row)

int main()
{
	cr::currWin().create(sf::VideoMode(40.f * 20.f, 40.f * 20.f), "Title", sf::Style::Close);
	sf::RenderWindow& winMain = cr::currWin();

	cr::setCols(40);
	cr::setRows(40);

	Map map;

	while (winMain.isOpen())
	{
		sf::Event evnt;
		while (winMain.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				winMain.close();
				break;
			}
		}
		winMain.clear(sf::Color::Black);

		map.Draw();

		winMain.display();
	}

	return 0;
}