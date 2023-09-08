#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"gamedisplay.h"


class balli
{
private:
	float radius;
	sf::CircleShape ball1;
public:

	int x, y;
	float speedx;
	float speedy;
	float closex = 0;
		float closey = 0;
		float distx = 0;
		float disty = 0;
		int distance = 0;
	balli()
	{
		;
	}
	balli(sf::RenderWindow& window)
	{
		this->radius = 10;
		this->x = 330;
		
		this->y = window.getSize().y / 3;
		this->speedx = 4;
		this->speedy = 4;
	}
	void draw(sf::RenderWindow& window)
	{
		ball1.setRadius(this->radius);
		ball1.setPosition(this->x, this->y);
		ball1.setFillColor(sf::Color::White);
		window.draw(ball1);
	}
	float ball_position(float n, float lower, float upper)
	{
		if (n < lower)
		{
			n = lower;
		}
		if (n > upper)
		{
			return upper;
		}
		else
			return n;
	}
	bool checkcollision(sf::CircleShape c, sf::RectangleShape r)
	{
		sf::FloatRect code = r.getLocalBounds();

		 closex = ball_position(c.getPosition().x, r.getPosition().x, r.getPosition().x + code.width); 
		
		 closey = ball_position(c.getPosition().y, r.getPosition().y, r.getPosition().y + code.width);
		 
		 distx = c.getPosition().x - closex;
		 
		 disty = c.getPosition().y - closey;
		 
		 distance = (distx) * (distx)+(disty) * (disty);

		if (distance < c.getRadius() * c.getRadius() && closey == c.getPosition().y)
		{
			return 1;
		}
		else if (distance < c.getRadius() * c.getRadius() && closex != c.getPosition().x && closey != c.getPosition().y)
		{
			return 1;
		}
		else if (distance < c.getRadius() * c.getRadius() && closex == c.getPosition().x)
		{
			return 1;
		}
	}
	void moveball(sf::RenderWindow& window, sf::CircleShape s, sf::RectangleShape& player1, sf::RectangleShape& player2, sf::RectangleShape& table)
	{
		this->x += speedx;
		this->y += speedy;
		if (this->y < 110)
		{
			this->y = 110;
			this->speedy *= -1;
			
		}
		if (this->y > 370)
		{
			this->y = 370;
			this->speedy *= -1;
			
		}
		if (this->x < 50)
		{
			this->x = 50;
			this->speedx *= -1;
			this->speedx ++;
		}
		if (this->x > 580)
		{
			this->x = 570;
			this->speedx *= -1;
			this->speedx ++;
		}
	}
	sf::CircleShape getball()
	{
		return ball1;
	}
};