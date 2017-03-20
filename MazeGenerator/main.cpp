#include "SFML\Graphics.hpp"

int main()
{
	sf::RenderWindow winMain(sf::VideoMode(750, 750), "Test", sf::Style::Close);
	winMain.setFramerateLimit(60);


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

		winMain.draw(sf::CircleShape(winMain.getSize().x / 2.f));

		winMain.display();
	}

	return 0;
}