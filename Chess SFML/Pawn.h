#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chess.h"

class Pawn : public Chess
{
public:
	void draw(sf::RenderWindow& window);
	void setColor(std::string color);
	void setSize(int);
	void setCoords(int, int);
	ChessStruct getSetting();

private:
	std::string color = "black";
	int x = 0;
	int y = 0;
	int size = 20;
};




