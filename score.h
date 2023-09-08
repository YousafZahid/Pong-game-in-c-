#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<Windows.h>
#include"ball.h"
using namespace std;
using namespace sf;

class score  
{
private:
	Font font;
	Text text;
	int  s=0;
public:
	Text getText()
	{
		return text;
	}
	score()
	{
		if (!font.loadFromFile("images/digits.ttf"))
			cout << "error " << endl;

		text.setFont(font);
		text.setPosition(0, 0);
		text.setCharacterSize(45);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold);
		string xc = to_string(s);
		text.setString(xc);
	}
	void setPosition(int x,int y)
	{
		text.setPosition(x, y);
	}
	void incscore()
	{
		s++;
		string xc = to_string(s);
		text.setString(xc);
	}
	int getscore()
	{
		return s;
	}
};