#pragma once
#include <SFML/Graphics.hpp>

class OutputTime
{
public:
	void setPosition(int, int);
	void setSize(int, int);
	void draw(sf::RenderWindow& window, sf::Time& time);
private:
	int x = 0;
	int y = 0;
	int size_x = 0;
	int size_y = 0;

};

