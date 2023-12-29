#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;


int authorspagee()
{
	bool openMenu1 = true;
	int choice = 0;

	RenderWindow menuWindow(VideoMode(1920, 1080), "authors");//width и height можно заменить на нужные значения
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(1920, 1080));//прямоугольник для фона

	Texture authorspage;
	authorspage.loadFromFile("images/authorspage.png");

	Sprite aut(authorspage);
	while (menuWindow.isOpen())
	{
		Event event;
		while (menuWindow.pollEvent(event))
		{
			if (event.type == Event::Closed or event.key.code == Keyboard::Escape)
			{
				menuWindow.close();
			}
		}
		while (openMenu1)
		{
			Event event2;
			while (menuWindow.pollEvent(event2))
			{
				if (event2.type == Event::Closed or event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
				}
			}
			menuWindow.clear();
			menubackground.setTexture(&authorspage);
			menuWindow.draw(menubackground);
			menuWindow.display();
			if (IntRect(707, 858, 522, 109).contains(Mouse::getPosition(menuWindow)))//проверка какой пункт меню выбран
			{
				choice = 1;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					openMenu1 = false;
					menuWindow.close();
					menu();
				}
			}
		}
	}
	return 0;
}
