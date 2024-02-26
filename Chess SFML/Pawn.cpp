#include "Pawn.h"

#include <SFML/Graphics.hpp>


void Pawn::draw(sf::RenderWindow& window) {
	sf::Texture pawntexture;
	if (color == "black") {
		pawntexture.loadFromFile("data/black_pawn.png");
	}
	else {
		pawntexture.loadFromFile("data/white_pawn.png");
	}
	sf::Sprite pawnsprite;
	pawnsprite.setTexture(pawntexture);
	pawnsprite.setPosition(x, y);
	
	pawnsprite.setScale((float)size / 255, (float)size / 255);
	window.draw(pawnsprite);
}

void Pawn::setColor(std::string str) {
	if (str == "white" || str == "black") {
	color = str;
	}
}