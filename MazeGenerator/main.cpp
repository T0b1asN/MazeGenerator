#include "curr.h"
#include "Map.h"
#include <Windows.h>
#include <ctime>

//Start and end chosen after generation (from top/bottom row)

void justShow();
void justSave();

int main()
{
	srand(static_cast <unsigned> (time(0)));
	std::cout << "Number of collumns: " << std::endl;
	int _cols;
	std::cin >> _cols;
	cr::setCols(_cols * 2 + 1);

	std::cout << "Number of rows: " << std::endl;
	int _rows;
	std::cin >> _rows;
	cr::setRows(_rows * 2 + 1);

	std::cout << "[s]how a random maze or [w]rite a random maze to a file" << std::endl;
	char in;
	std::cin >> in;
	if (in == 's' || in == 'S')
		justShow();
	else if (in == 'w' || in == 'W')
		justSave();
	else
	{
		std::cout << "Wrong input!" << std::endl;
		Sleep(1500);
	}
	return 0;
}

void justShow()
{
	cr::currWin().create(sf::VideoMode((float)cr::getCols() * (750.f / (float)cr::getCols()), 
		(float)cr::getRows() * (750.f / (float)cr::getRows())), Title, sf::Style::Close);
	cr::currWin().setFramerateLimit(60);
	sf::RenderWindow& winMain = cr::currWin();

	winMain.setFramerateLimit(60);

	Map map(sf::Vector2i(cr::getCols() / 2, cr::getRows() / 2));

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
}

void justSave()
{
	Map map(sf::Vector2i(1, 1));

	sf::Clock clock;
	clock.restart();
	map.GenerateMaze();
	std::cout << "Needed time (in seconds): " << clock.getElapsedTime().asSeconds() << std::endl;

	std::string path;
	std::cout << "enter filename" << std::endl;
	std::cin >> path;
	path = "res\\" + path;
	map.toImage(path);
}
