#pragma once
#include <SFML/Graphics.hpp>

class Board
{
public:
	void draw(sf::RenderWindow& window, int height, int width);
    void setPosition(int, int);
private:
    int x = 0, y = 0;
};

void Board::draw(sf::RenderWindow& window, int height, int width) {
    sf::RectangleShape rectangle0(sf::Vector2f(height + 10, height + 10));
    rectangle0.setFillColor(sf::Color(0, 0, 0, 0));
    rectangle0.setOutlineThickness(5);
    rectangle0.setOutlineColor(sf::Color(0, 0, 0));
    rectangle0.setPosition(0, 0);
    window.draw(rectangle0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i % 2 != j % 2) {
            sf::RectangleShape rectangle(sf::Vector2f(height / 8, height / 8));
            rectangle.setFillColor(sf::Color(40, 20, 10));
            rectangle.setPosition(x + i * (height / 8),  y + j * (height / 8));
            window.draw(rectangle);
            }
        }
    }
}
void Board::setPosition(int x1, int y1) {
    x = x1;
    y = y1;
}