#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include <time.h>
#include <string>

int width = 400;
int height = 533;
int isClosed = 0;
using namespace sf;

struct point
{
    int x, y;
};

bool checkPlatformOverlap(const point& p1, const point& p2)
{
    int platformWidth = 68;
    int platformHeight = 14;

    // Проверяем пересечение по горизонтали
    bool horizontalOverlap = (p1.x + platformWidth >= p2.x) && (p2.x + platformWidth >= p1.x);

    // Проверяем пересечение по вертикали
    bool verticalOverlap = (p1.y + platformHeight >= p2.y) && (p2.y + platformHeight >= p1.y);

    return horizontalOverlap && verticalOverlap;
}

int game()
{
    srand(time(0));
    if (isClosed == 1)
    {
        return 0;
    }

    RenderWindow app(VideoMode(width, height), "Start Doodle Game");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, coin;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    coin.loadFromFile("images/coin.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];

    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % width;
        plat[i].y = rand() % height;

        // Проверяем пересечение с предыдущими платформами
        for (int j = 0; j < i; j++)
        {
            if (checkPlatformOverlap(plat[i], plat[j]))
            {
                // Если есть пересечение, генерируем новые координаты
                plat[i].x = rand() % width;
                plat[i].y = rand() % height;

                // Повторно проверяем пересечение с предыдущими платформами
                j = -1;
            }
        }
    }

    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;
    int score = 0;
    int charHeight = 0;
    int coinX = 0, coinY = 0;
    int coinCount = 0;
    int visibleCheck = 0;

    Font font;
    font.loadFromFile("font/arial.ttf");

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10, 10);
    scoreText.setFillColor(Color::White);
    scoreText.setColor(Color::Red);

    Text coinCounter;
    coinCounter.setFont(font);
    coinCounter.setCharacterSize(20);
    coinCounter.setPosition(180, 10);
    coinCounter.setFillColor(Color::White);
    coinCounter.setColor(Color::Yellow);


    while (app.isOpen())//пока окно приложения открыто
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))//управление
            x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left))//управление
            x -= 3;

        dy += 0.2;
        y += dy;
        if (y > 500)
            dy = -10;

        if (y < h)
        {
            for (int i = 0; i < 10; i++)
            {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > height)
                {
                    plat[i].y = 0;
                    plat[i].x = rand() % width;
                }
            }
        }
        if (score <= 300)
        {
            for (int i = 0; i < 10; i++)
            {
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                {
                    dy = -10;
                    score += 10; // Увеличиваем счетчик очков
                }
            }
        }
        if (score >= 300 && 500 > score)
        {
            for (int i = 0; i < 7; i++)
            {
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                {
                    dy = -10;
                    score += 10; // Увеличиваем счетчик очков
                }
            }
        }
        if (score >= 500 && 800 > score)
        {
            for (int i = 0; i < 6; i++)
            {
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                {
                    dy = -10;
                    score += 10; // Увеличиваем счетчик очков
                }
            }
        }
        if (score >= 800)
        {
            for (int i = 0; i < 5; i++)
            {
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                {
                    dy = -10;
                    score += 10; // Увеличиваем счетчик очков
                }
            }
        }
        if (x < -50)
            x = width;
        else if (x > width)
            x = -50;

        if (y > 500)
        {
            x = 100;
            y = 100;
            for (int i = 0; i < 10; i++)
            {
                plat[i].y = rand() % height;

                // Проверяем пересечение с предыдущими платформами
                for (int j = 0; j < i; j++)
                {
                    if (checkPlatformOverlap(plat[i], plat[j]))
                    {
                        // Если есть пересечение, генерируем новые координаты
                        plat[i].y = rand() % height;

                        // Повторно проверяем пересечение с предыдущими платформами
                        j = -1;
                    }
                }
            }
            dy = 0;
            score = 0; // Сбрасываем счетчик пройденной высоты при достижении нижней границы
            charHeight = 0;
        }

        sPers.setPosition(x, y);
        app.draw(sBackground);
        app.draw(sPers);
        if (score <= 300)
        {
            for (int i = 0; i < 10; i++)
            {
                if (plat[i].x != 0 && plat[i].y != 0)
                {
                    sPlat.setPosition(plat[i].x, plat[i].y);
                    app.draw(sPlat);
                }
            }
        }
        if (score >= 300 && 500 > score)
        {
            for (int i = 0; i < 7; i++)
            {
                if (plat[i].x != 0 && plat[i].y != 0)
                {
                    sPlat.setPosition(plat[i].x, plat[i].y);
                    app.draw(sPlat);
                }
            }
        }
        if (score >= 500 && 800 > score)
        {
            for (int i = 0; i < 6; i++)
            {
                if (plat[i].x != 0 && plat[i].y != 0)
                {
                    sPlat.setPosition(plat[i].x, plat[i].y);
                    app.draw(sPlat);
                }
            }
        }
        if (score >= 800)
        {
            for (int i = 0; i < 5; i++)
            {
                if (plat[i].x != 0 && plat[i].y != 0)
                {
                    sPlat.setPosition(plat[i].x, plat[i].y);
                    app.draw(sPlat);
                }
            }
        }




        // Обновляем текст счетчика
        scoreText.setString("Score: " + std::to_string(score));
        app.draw(scoreText);

        app.display();
    }

    return 0;
}
