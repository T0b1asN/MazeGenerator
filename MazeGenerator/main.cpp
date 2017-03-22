#include "curr.h"
#include "Map.h"

//Start and end chosen after generation (from top/bottom row)

int main()
{
	cr::currWin().create(sf::VideoMode(40.f * 20.f, 40.f * 20.f), "Title", sf::Style::Close);
	cr::currWin().setFramerateLimit(60);
	sf::RenderWindow& winMain = cr::currWin();

	winMain.setFramerateLimit(1);

	cr::setCols(39);
	cr::setRows(39);

	Map map;
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
		if (i = 60)
			map.GenerationStep();

		winMain.clear(sf::Color::Black);

		map.Draw();

		winMain.display();

		if (i = 1000)
			i = 0;
		i++;
		std::cout << "i: " << i << std::endl;
	}

	return 0;
}