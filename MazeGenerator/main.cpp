#include "curr.h"
#include "Map.h"

//Start and end chosen after generation (from top/bottom row)

int main()
{
	cr::currWin().create(sf::VideoMode(49.f * 10.f, 29.f * 10.f), "Title", sf::Style::Close);
	cr::currWin().setFramerateLimit(60);
	sf::RenderWindow& winMain = cr::currWin();

	winMain.setFramerateLimit(60);

	cr::setCols(49);
	cr::setRows(29);

	Map map(sf::Vector2i(1, 1));
	
	while (!map.isFinished())
	{
		map.GenerationStep();
	}

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