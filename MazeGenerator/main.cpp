#include "curr.h"
#include "Map.h"

//Start and end chosen after generation (from top/bottom row)

int main()
{
	cr::currWin().create(sf::VideoMode(40.f * 20.f, 40.f * 20.f), "Title", sf::Style::Close);
	cr::currWin().setFramerateLimit(60);
	sf::RenderWindow& winMain = cr::currWin();

	winMain.setFramerateLimit(60);

	cr::setCols(19);
	cr::setRows(19);

	Map map(sf::Vector2i(1, 1));
	int i = 0;
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
		if (i >= 5)
		{
			map.GenerationStep();
			i = 0;
		}

		winMain.clear(sf::Color::Black);

		map.Draw();

		winMain.display();
		i++;
	}

	return 0;
}