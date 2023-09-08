#pragma once
#include<iostream>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"mainmenu.h"
#include"score.h"
#include"ball.h"

using namespace std;

using namespace sf;

class display : public balli
{

    Texture playertex;
    Texture tabletex;
    RectangleShape player1;
    RectangleShape player2;
    CircleShape ball;
    RectangleShape table;
    RectangleShape winner1;
    Texture winnertex1;
    Texture winnertex2;
    RectangleShape winner2;
    Font font, pl1, pl2;
    Text P1, P2;

public:

    int increase_speed1 = 0, increase_speed2 = 0;
    int  p1y = 110, p2y = 110,i=0;
    bool p1flag = 0, p2flag = 0;
    score score1, score2;
    balli* b;

    display()
    {
        player1.setSize(Vector2f(80.f, 80.f));
        player2.setSize(Vector2f(80.f, 80.f));

        playertex.loadFromFile("racket.png");

        player1.setPosition(65.f, 107.f);
        player1.setTexture(&playertex);
        player1.getInverseTransform();

        player2.setPosition(520.f, 107.f);
        player2.setTexture(&playertex);
        player2.getInverseTransform();

        ball.setRadius(10.f);
        ball.setPosition(90.f, 125.f);
        ball.setFillColor(sf::Color::Black);

        tabletex.loadFromFile("table.png");
        table.setTexture(&tabletex);
        table.setSize(Vector2f(700.f, 500.f));

        winnertex1.loadFromFile("images/player1win.jpg");
        winner1.setTexture(&winnertex1);
        winner1.setSize(Vector2f(700.f, 500.f));

        winnertex2.loadFromFile("images/player2win.jpg");
        winner2.setTexture(&winnertex2);
        winner2.setSize(Vector2f(700.f, 500.f));

        font.loadFromFile("fonts/pong.ttf");
        pl1.loadFromFile("fonts/pong.ttf");
        pl2.loadFromFile("fonts/pong.ttf");

        P1.setFont(font);
        P1.setCharacterSize(25);
        P1.setStyle(Text::Bold);
        P1.setPosition(80, 0);

        P2.setFont(font);
        P2.setCharacterSize(25);
        P2.setStyle(Text::Bold);
        P2.setPosition(410, 0);

        P1.setString("PLAYER ONE");
        P2.setString("PLAYER TWO");
    }
    void twoplayer()
    {
        RenderWindow window(sf::VideoMode(700, 500), "PONG GAME", sf::Style::Titlebar | sf::Style::Close);        
        this->b = new balli(window);
        window.setFramerateLimit(60);
        while (window.isOpen())
        {
            sf::Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                {
                    window.close();
                }
            }

            if (Keyboard::isKeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Key::W))
                {
                    if (p1y == 105 && Keyboard::isKeyPressed(Keyboard::Key::W))
                    {
                        player1.setPosition(65, 105);
                    }
                    else
                    {
                        player1.move(0, -5.f);
                        p1y -= 5;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Key::S))
                {
                    if (p1y == 340 && Keyboard::isKeyPressed(Keyboard::Key::S))
                    {
                        player1.setPosition(65, 340);
                    }
                    else
                    {
                        player1.move(0, +5.f);
                        p1y += 5;
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Key::I))
                {
                    if (p2y == 105 && Keyboard::isKeyPressed(Keyboard::Key::I))
                    {
                        player2.setPosition(520, 105);
                    }
                    else
                    {
                        player2.move(0, -5.f);
                        p2y -= 5;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Key::K))
                {
                    if (p2y == 340 && Keyboard::isKeyPressed(Keyboard::Key::K))
                    {
                        player2.setPosition(520, 340);
                    }
                    else
                    {
                        player2.move(0, +5.f);
                        p2y += 5;
                    }
                }
            }

            if (b->x > 550)
            {
                if (score1.getscore() == 9)
                {


                    while (1)
                    {
                        window.clear();
                        window.draw(winner1);
                        window.display();
                    }
                }
                else
                {
                    score1.incscore();
                    b->x = 330;
                    b->y = 240;
                    p1flag = 0;
                    p2flag = 0;
                    b->speedx = 4;
                }
            }

            else if (b->x < 90)
            {
                if (score2.getscore() == 9)
                {
                    while (1)
                    {
                        window.clear();
                        window.draw(winner2);
                        window.display();

                    }
                }
                else
                {
                    score2.incscore();
                    b->x = 330;
                    b->y = 240;
                    p1flag = 0;
                    p2flag = 0;
                    b->speedx = 4;
                }
            }
            else
            {
                if (p1flag == 0)
                {

                    if (checkcollision(b->getball(), player1) == 1)
                    {
                        b->speedx *= -1;
                        if (increase_speed1 = 2)
                        {
                            increase_speed1 = 0;
                            b->speedx++;
                        }
                        increase_speed1++;
                        p1flag = 1;
                        p2flag = 0;
                    }
                }
                if (p2flag == 0)
                {
                    if (checkcollision(b->getball(), player2) == 1)
                    {
                        b->speedx *= -1;
                        
                        if (increase_speed2 = 2)
                        {
                            increase_speed2 = 0;
                            b->speedx--;

                        }
                        increase_speed2++;
                        p1flag = 0;
                        p2flag = 1;
                    }
                }
            }

            window.clear();

            score1.setPosition(80, 30);
            score2.setPosition(430, 30);

            b->moveball(window, b->getball(), player1, player2, table);

            window.draw(table);
            window.draw(player1);
            window.draw(player2);

            b->draw(window);

            window.draw(score1.getText());
            window.draw(score2.getText());

            window.draw(P1);
            window.draw(P2);
            window.display();
        }
    }
    void singleplayer()
    {
        RenderWindow window(sf::VideoMode(700, 500), "PONG GAME", sf::Style::Titlebar | sf::Style::Close);
        this->b = new balli(window);
        window.setFramerateLimit(60);

        while (window.isOpen())
        {
            sf::Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                {
                    window.close();
                }
            }

            if (Keyboard::isKeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Key::W))
                {
                    if (p1y == 105 && Keyboard::isKeyPressed(Keyboard::Key::W))
                    {
                        player1.setPosition(65, 105);
                    }
                    else
                    {
                        player1.move(0, -5.f);
                        p1y -= 5;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Key::S))
                {
                    if (p1y == 340 && Keyboard::isKeyPressed(Keyboard::Key::S))
                    {
                        player1.setPosition(60, 340);
                    }
                    else
                    {
                        player1.move(0, +5.f);
                        p1y += 5;
                    }
                }
                if (p2y >= 340)
                {
                    player2.setPosition(520, 340);
                }
                if (p2y <= 110)
                {
                    player2.setPosition(520, 110);
                }
            }
            if (b->x > 200)
            {
                player2.setPosition(520, b->y+1);
            }
            i++;
         
            if (i > 10)
            {
                i = 4;
            }
            if (b->x > 550)
            {
                if (score1.getscore() == 9)
                {
                    while (1)
                    {
                        window.clear();
                        window.draw(winner1);

                        window.display();
                    }
                }
                else
                {
                    score1.incscore();
                    b->x = 330;
                    b->y = 240;
                    b->speedx = 4;
                    p1flag = 0;
                    p2flag = 0;
                }
            }

            else if (b->x < 90)
            {
                if (score2.getscore() == 9)
                {
                    while (1)
                    {
                        window.clear();
                        window.draw(winner2);
                        window.display();
                    }
                }
                else
                {
                    score2.incscore();
                    b->x = 330;
                    b->y = 240;
                    b->speedx = 4;
                    p1flag = 0;
                    p2flag = 0;

                }
            }
            else
            {

                if (p1flag == 0)
                {

                    if (checkcollision(b->getball(), player1) == 1)
                    {
                        b->speedx *= -1;
                        if (increase_speed1 = 2)
                        {
                            b->speedx++;
                            increase_speed1 = 0;
                        }
                        increase_speed1++;
                        p1flag = 1;
                        p2flag = 0;

                    }
                }
                if (p2flag == 0)
                {
                    if (checkcollision(b->getball(), player2) == 1)
                    {
                        b->speedx *= -1;
                        if (increase_speed2 = 2)
                        {
                            b->speedx--;
                            increase_speed2 = 0;
                        }
                         increase_speed2++;
                        p1flag = 0;
                        p2flag = 1;

                    }
                }
            }

            window.clear();

            score1.setPosition(80, 30);
            score2.setPosition(430, 30);

            b->moveball(window, b->getball(), player1, player2, table);

            window.draw(table);
            window.draw(player1);

            b->draw(window);

            window.draw(score1.getText());
            window.draw(score2.getText());
            window.draw(player2);

            window.draw(P1);
            window.draw(P2);

            window.display();
        }
    }
};