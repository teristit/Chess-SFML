#include "OutputTime.h"


void OutputTime::setPosition(int x1, int y1) {
	x = x1;
	y = y1;
}


void OutputTime::setSize(int x1, int y1) {
	size_x = x1;
	size_y = y1;
}


void OutputTime::draw(sf::RenderWindow& window, sf::Time& time) {
    sf::RectangleShape rectangle(sf::Vector2f(150, 50));
    rectangle.setFillColor(sf::Color(0, 0, 0));
    rectangle.setPosition(x, y);
    window.draw(rectangle);


    sf::Font font;
    font.loadFromFile("font/arial.ttf");
    sf::Text text0;
    sf::Text text1;
    sf::Text text2;

    std::string sec = " " + std::to_string((int)time.asSeconds() % 60);
    std::string min = " " + std::to_string((int)time.asSeconds() / 60);

    text0.setFont(font);
    text1.setFont(font);
    text2.setFont(font);
    text0.setString(min);
    text1.setString(":");
    text2.setString(sec);
    text0.setCharacterSize((int)(size_y * 0.8));
    text1.setCharacterSize((int)(size_y * 0.8));
    text2.setCharacterSize((int)(size_y * 0.8));

    text0.setFillColor(sf::Color(255, 0, 0));
    text1.setFillColor(sf::Color(255, 0, 0));
    text2.setFillColor(sf::Color(255, 0, 0));
    text0.setStyle(sf::Text::Bold);
    text1.setStyle(sf::Text::Bold);
    text2.setStyle(sf::Text::Bold);
    text0.setPosition(x + 1, (int)(y + size_y * 0.05));
    text1.setPosition((int)(x + size_x * 0.5), (int)(y + size_y * 0.05));
    text2.setPosition((int)(x + size_x * 0.5 + 2), (int)(y + size_y * 0.05));
    window.draw(text0);
    window.draw(text1);
    window.draw(text2);
}