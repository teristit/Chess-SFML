#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Chess
{
public:
	struct ChessStruct
	{
		std::string name; std::string color; int x; int y; bool alive;
	};
	void draw(sf::RenderWindow& window);
	void setColor(std::string color);
	void setSize(int);
	void setCoords(int, int);
	void setName(std::string);
	void dead();
	bool move(Chess*, int, int);
	ChessStruct getSetting();
private:
	std::string name = "pawn";
	std::string color = "black";
	int x = 0;
	int y = 0;
	int size = 20;
	int direction = 1;
	bool pawn(Chess*, int, int);
	bool rook(Chess*, int, int);
	bool knight(Chess*, int, int);
	bool bishop(Chess*, int, int);
	bool queen(Chess*, int, int);
	bool king(Chess*, int, int);
	bool alive = 1;
};

