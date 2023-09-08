#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include<SFML/Audio.hpp>
using namespace std;

class timer {
private:
    sf::Font font;
    sf::Text text;
    long t;
    long tim;
    //sf::RectangleShape rect;

public:

    timer() 
    {
        if (!font.loadFromFile("images/digits.ttf"))
            cout << "error " << endl;

        text.setFont(font);
        
        text.setString("#4");
        
        text.setPosition(0, 0);
        
        text.setCharacterSize(45);
        
        text.setFillColor(sf::Color::White);
        
        text.setStyle(sf::Text::Bold);
        
        t = time(0);
    }
    long timers(sf::RenderWindow& window, bool et)
    {
        // tim = time(3);
        sf::RectangleShape shape(sf::Vector2f(50.0f, 40.0f));
        shape.setFillColor(sf::Color::Black);
        shape.move(sf::Vector2f(0, 0));

        if (!et)
            tim = time(0) - t;
        if (et)
        {
            return tim;
        }
        string xc = to_string(tim);
        text.setString(xc);
        window.draw(shape);
        window.draw(text);
    }
};