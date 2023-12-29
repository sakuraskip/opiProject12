<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;


int moreAbout()
{
	bool openMenu2 = true;
	int choice = 0;

	RenderWindow menuWindow(VideoMode(1920, 1080), "more about us");//width и height можно заменить на нужные значения
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(1920, 1080));//прямоугольник для фона

	Texture aboutUs;
	aboutUs.loadFromFile("images/qrcode.png");

	Sprite about(aboutUs);
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
		while (openMenu2)
		{
			Event event2;
			while (menuWindow.pollEvent(event2))
			{
				if (event2.type == Event::Closed or event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
					openMenu2 = false;
				}
			}
			menuWindow.clear();
			menubackground.setTexture(&aboutUs);
			menuWindow.draw(menubackground);
			menuWindow.display();
			if (IntRect(6, 999, 465, 68).contains(Mouse::getPosition(menuWindow)))//проверка какой пункт меню выбран
			{
				choice = 1;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					openMenu2 = false;
					menuWindow.close();
					menu();
				}
			}
		}
		return 0;
	}
=======
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;


int moreAbout()
{
	bool openMenu2 = true;
	int choice = 0;

	RenderWindow menuWindow(VideoMode(1920, 1080), "more about us");//width и height можно заменить на нужные значения
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(1920, 1080));//прямоугольник для фона

	Texture aboutUs;
	aboutUs.loadFromFile("images/qrcode.png");

	Sprite about(aboutUs);
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
		while (openMenu2)
		{
			Event event2;
			while (menuWindow.pollEvent(event2))
			{
				if (event2.type == Event::Closed or event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
					openMenu2 = false;
				}
			}
			menuWindow.clear();
			menubackground.setTexture(&aboutUs);
			menuWindow.draw(menubackground);
			menuWindow.display();
			if (IntRect(6, 999, 465, 68).contains(Mouse::getPosition(menuWindow)))//проверка какой пункт меню выбран
			{
				choice = 1;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					openMenu2 = false;
					menuWindow.close();
					menu();
				}
			}
		}
		return 0;
	}
>>>>>>> 66cad6d34c7bf69efa7783a7f1b424ac486609e0
}