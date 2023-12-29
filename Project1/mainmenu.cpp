<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;

float width = 1920;
float height = 1080;//для ширины и высоты окна меню


int menu()
{
    bool openMenu = true;
	int choice = 0;
	
	RenderWindow menuWindow(VideoMode(width, height), "name?");//width и height можно заменить на нужные значения
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(width, height));//прямоугольник для фона

	Font font;
	font.loadFromFile("font/lucidaconsole.ttf");


	Texture mainMenu,menuAuthors,authorspage;
	mainMenu.loadFromFile("images/menu.png");
	menuAuthors.loadFromFile("images/menuauthors.png");
	authorspage.loadFromFile("images/authorspage.png");

	
	Sprite menu(mainMenu), authors(menuAuthors);

	menu.setPosition(0, 0);

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
		while (openMenu)
		{
			Event event2;
			while (menuWindow.pollEvent(event2))
			{
				if (event2.type == Event::Closed or event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
				}
			}
			choice = 0;
			menuWindow.clear();
			menuWindow.draw(menubackground);
			menuWindow.draw(menu);
			menuWindow.display();

			if (IntRect(54, 445, 510, 84).contains(Mouse::getPosition(menuWindow)))//проверка какой пункт меню выбран
			{
				choice = 1;
			}
			if (IntRect(74, 637, 510, 56).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 2;
			}
			if (IntRect(60, 749, 506, 54).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 3;
			}
			if (IntRect(68, 871, 510, 74).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 4;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					menuWindow.close();//меню закрывается и открывается игра
					openMenu = false;
					game();
				}
				if (choice == 2)//авторы
				{
					menuWindow.close();
					authorspagee();
						
				}
				if (choice == 3)//код на гитхаб
				{
					menuWindow.close();
					moreAbout();
				}
				if (choice == 4)//выход
				{
					menuWindow.close();
					openMenu = false;
					return 1;
					exit(0);
					
				}

			}
			
		}
	}
	return 0;
=======
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;

float width = 1920;
float height = 1080;//для ширины и высоты окна меню


int menu()
{
    bool openMenu = true;
	int choice = 0;
	
	RenderWindow menuWindow(VideoMode(width, height), "name?");//width и height можно заменить на нужные значения
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(width, height));//прямоугольник для фона

	Font font;
	font.loadFromFile("font/lucidaconsole.ttf");


	Texture mainMenu,menuAuthors,authorspage;
	mainMenu.loadFromFile("images/menu.png");
	menuAuthors.loadFromFile("images/menuauthors.png");
	authorspage.loadFromFile("images/authorspage.png");

	
	Sprite menu(mainMenu), authors(menuAuthors);

	menu.setPosition(0, 0);

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
		while (openMenu)
		{
			Event event2;
			while (menuWindow.pollEvent(event2))
			{
				if (event2.type == Event::Closed or event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
				}
			}
			choice = 0;
			menuWindow.clear();
			menuWindow.draw(menubackground);
			menuWindow.draw(menu);
			menuWindow.display();

			if (IntRect(54, 445, 510, 84).contains(Mouse::getPosition(menuWindow)))//проверка какой пункт меню выбран
			{
				choice = 1;
			}
			if (IntRect(74, 637, 510, 56).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 2;
			}
			if (IntRect(60, 749, 506, 54).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 3;
			}
			if (IntRect(68, 871, 510, 74).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 4;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					menuWindow.close();//меню закрывается и открывается игра
					openMenu = false;
					game();
				}
				if (choice == 2)//авторы
				{
					menuWindow.close();
					authorspagee();
						
				}
				if (choice == 3)//код на гитхаб
				{
					menuWindow.close();
					moreAbout();
				}
				if (choice == 4)//выход
				{
					menuWindow.close();
					openMenu = false;
					return 1;
					
				}

			}
			
		}
	}
	return 0;
>>>>>>> 66cad6d34c7bf69efa7783a7f1b424ac486609e0
}