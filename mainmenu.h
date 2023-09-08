#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<Windows.h>
using namespace std;
using namespace sf;
class intro 
{
private:
    Texture startup;
    Sprite start;

    Font font, player1, player2;
    Text text1, p1, p2;

public:
    intro()
    {
        startup.loadFromFile("main4.jpg");
        start.setTexture(startup);

        font.loadFromFile("fonts/pong.ttf");
        player1.loadFromFile("fonts/pong.ttf");
        player2.loadFromFile("fonts/pong.ttf");
        
        text1.setFont(font);
        text1.setCharacterSize(38);
        text1.setStyle(Text::Bold);
        text1.setPosition(345, 360);
      
        p1.setFont(font);
        p1.setCharacterSize(40);
        p1.setStyle(Text::Bold);
        p1.setPosition(360, 310);
        
        p2.setFont(font);
        p2.setCharacterSize(40);
        p2.setStyle(Text::Bold);
        p2.setPosition(360, 370);
       
        text1.setString("PRESS ENTER TO PLAY");
     
        p1.setString("ONE PLAYER");
        p2.setString("TWO PLAYER");
    }
    int intro1()
    {
        sf::RenderWindow startscreen(sf::VideoMode(1050, 780), "START SCREEN");
        bool flag1 = true;
       
        while (startscreen.isOpen())
        {
            if (flag1 == 1)
            {
                sf::Event event1;
                char key = GetAsyncKeyState(VK_RETURN);
                while (startscreen.pollEvent(event1))
                {
                    if (key)
                    {
                        flag1 = false;
                    }
                }
                startscreen.clear();
                startscreen.draw(start);
                startscreen.draw(text1);
                startscreen.display();
            }
            else
            {
                Vector2i pos = Mouse::getPosition(startscreen);
                int x = pos.x;
                int y = pos.y;
                Event event1;
                while (startscreen.pollEvent(event1))
                {
                    if(event1.type == Event::MouseMoved)
                    {
                        p1.setFillColor(Color::White);
                        p2.setFillColor(Color::White);
                        if (y >= 323 && y <= 355 && x >= 353 && x <= 620)
                        {
                            p1.setFillColor(Color::Red);
                        }
                        else if (y >= 390 && y <= 421 && x >= 353 && x <= 620)
                        {
                            p2.setFillColor(Color::Red);
                        }
                    }
                    if (event1.type == Event::MouseButtonPressed)
                    {
                        if (event1.key.code == Mouse::Left)
                        {
                            if (y >= 323 && y <= 355 && x >= 353 && x <= 620)
                            {
                                startscreen.close();
                                return 0;
                            }
                            else if (y >= 390 && y <= 421 && x >= 353 && x <= 620)
                            {
                                startscreen.close();
                                return 1;
                            }
                         
                        }
                    }
                }
                startscreen.draw(start);
                startscreen.draw(p1);
                startscreen.draw(p2);
                startscreen.display();
            }
        }
    }
};