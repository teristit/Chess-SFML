#include "Textend.h"
#include <iostream>
#include <string>

void Textend::the_end(sf::RenderWindow& window, int x) {
	sf::Font font;
	font.loadFromFile("font/arial.ttf");
	sf::Text text;
	std::string s = " " + std::to_string(x);

	text.setFont(font);
	text.setString((" \n" + s));
	text.setCharacterSize(50);

	text.setFillColor(sf::Color(255, 0, 0));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(100, 100);
	window.draw(text);
}