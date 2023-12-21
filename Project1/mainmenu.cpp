#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <Windows.h>

using namespace sf;

float width = 600;
float height = 675;//��� ������ � ������ ���� ����


int menu()
{
	bool openMenu = true;
	int choice = 0;
	
	RenderWindow menuWindow(VideoMode(width, height), "name?");//width � height ����� �������� �� ������ ��������
	menuWindow.setFramerateLimit(15);
	RectangleShape menubackground(Vector2f(width, height));//������������� ��� ����

	Font font;
	font.loadFromFile("font/lucidaconsole.ttf");

	Texture backgroundTexture;//���� ��� ��������
	backgroundTexture.loadFromFile("images/menubackground1.jpg");//����� �������� � ����� ���������
	menubackground.setTexture(&backgroundTexture);

	Texture mainMenu;
	mainMenu.loadFromFile("images/menu.png");
	
	Sprite menu(mainMenu);

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

			if (IntRect(184, 263, 225, 48).contains(Mouse::getPosition(menuWindow)))//�������� ����� ����� ���� ������
			{
				choice = 1;
			}
			if (IntRect(189, 384, 220, 30).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 2;
			}
			if (IntRect(183, 452, 225, 34).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 3;
			}
			if (IntRect(185, 529, 226, 44).contains(Mouse::getPosition(menuWindow)))
			{
				choice = 4;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (choice == 1)
				{
					menuWindow.close();//���� ����������� � ����������� ����
					openMenu = false;
				}
				if (choice == 2)//��������� �������� � ��������
				{
					
				}
				if (choice == 3)//��-���� ��������
				{

				}
				if (choice == 4)
				{
					menuWindow.close();
					openMenu = false;
					return 1;
					
				}

			}
			menuWindow.draw(menubackground);
			menuWindow.draw(menu);
			menuWindow.display();
		}
	}
	return 0;
}