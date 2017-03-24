#include "curr.h"
#include "Map.h"
#include <ctime>

//Start and end chosen after generation (from top/bottom row)

int main()
{
	srand(static_cast <unsigned> (time(0)));
	cr::currWin().create(sf::VideoMode(99.f * 5.f, 99.f * 5.f), "Title", sf::Style::Close);
	cr::currWin().setFramerateLimit(60);
	sf::RenderWindow& winMain = cr::currWin();

	winMain.setFramerateLimit(25);

	cr::setCols(99);
	cr::setRows(99);

	Map map(sf::Vector2i(1, 1));

	sf::Clock clock;
	clock.restart();
	map.GenerateMaze_Bias();
	std::cout << "Needed time (in seconds): " << clock.getElapsedTime().asSeconds() << std::endl;

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