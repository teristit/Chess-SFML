#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Chess.h"
#include "Textend.h"
#include "OutputTime.h"

int main()
{
    const int height = 640, width = 640;
    int size = 80;
    int X0 = -1, Y0 = -1, X1 = -1, Y1 = -1;
    int v = 0;
    std::string player_color = "white";
    sf::RenderWindow window(sf::VideoMode(height + 400 , width + 200), "Chess", sf::Style::Close);
    sf::Clock clock;
    sf::Time time_white = clock.getElapsedTime();
    sf::Time time_black = clock.getElapsedTime();
    OutputTime white_output_time;
    OutputTime black_output_time;
    white_output_time.setSize(150, 50);
    white_output_time.setPosition(700, 100);
    black_output_time.setSize(150, 50);
    black_output_time.setPosition(700, 200);


    Board board;
    Chess::ChessStruct list[] = {
        {"rook", "black", 0, 0}, {"knight", "black", 1, 0} , {"bishop", "black", 2, 0} , {"queen", "black", 3, 0}, {"king", "black", 4, 0}, {"bishop", "black", 5, 0}, {"knight", "black", 6, 0}, {"rook", "black", 7, 0},
        {"pawn", "black", 0, 1}, {"pawn", "black", 1, 1}, {"pawn", "black", 2, 1}, {"pawn", "black", 3, 1}, {"pawn", "black", 4, 1}, {"pawn", "black", 5, 1}, {"pawn", "black", 6, 1}, {"pawn", "black", 7, 1},
        {"pawn", "white", 0, 6}, {"pawn", "white", 1, 6}, {"pawn", "white", 2, 6}, {"pawn", "white", 3, 6}, {"pawn", "white", 4, 6}, {"pawn", "white", 5, 6}, {"pawn", "white", 6, 6}, {"pawn", "white", 7, 6},
        {"rook", "white", 0, 7}, {"knight", "white", 1, 7} , {"bishop", "white", 2, 7} , {"queen", "white", 3, 7}, {"king", "white", 4, 7}, {"bishop", "white", 5, 7}, {"knight", "white", 6, 7}, {"rook", "white", 7, 7} };

    Chess chees_pieces[32];
    for (int i = 0; i < 32; i++) {
        chees_pieces[i] = Chess();
        chees_pieces[i].setName(list[i].name);
        chees_pieces[i].setColor(list[i].color);
        chees_pieces[i].setCoords(list[i].x, list[i].y);
        chees_pieces[i].setSize(size);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    sf::Vector2i position = sf::Mouse::getPosition();
                    bool flagposition = 0;
                    int x = 0, y = 0;
                    x = (position.x - window.getPosition().x) / size;
                    y = (position.y - window.getPosition().y - 38) / size;
                    v = position.y - window.getPosition().y;
                    for (int i = 0; i < 32; i++) {

                        if (chees_pieces[i].getSetting().x == x && chees_pieces[i].getSetting().y == y && 
                            chees_pieces[i].getSetting().alive && chees_pieces[i].getSetting().color == player_color) {
                            flagposition = 1;

                        }
                    }
                    if (flagposition && X0 == -1 && Y0 == -1) {
                        X0 = x;
                        Y0 = y;
                    }
                    else  if (X0 != -1 && Y0 != -1 && (X0 != x || Y0 != y)) {
                        X1 = x;
                        Y1 = y;
                    }
                    if (X0 != -1 && Y0 != -1 && X1 != -1 && Y1 != -1) {
                        for (int i = 0; i < 32; i++) {
                            if (chees_pieces[i].getSetting().x == X0 && chees_pieces[i].getSetting().y == Y0 &&
                                chees_pieces[i].getSetting().alive) {
                                bool l = chees_pieces[i].move(chees_pieces, X1, Y1);
                                if (l) {
                                    if (player_color == "white") {
                                        player_color = "black";
                                    }
                                    else {
                                        player_color = "white";
                                    }
                                }
                                X0 = -1, Y0 = -1, X1 = -1, Y1 = -1;
                            }
                        }
                    }
                }
            }
        }

        if (player_color == "white") {
            time_white += clock.getElapsedTime();
        }
        else {
            time_black += clock.getElapsedTime();
        }
        clock.restart();

        window.clear(sf::Color(255, 255, 220));
        board.draw(window, height, width);
        sf::RectangleShape rectangle0(sf::Vector2f(size, size));
        rectangle0.setFillColor(sf::Color(200, 20, 20, 100));
        rectangle0.setPosition(X0 * size, Y0 * size);
        window.draw(rectangle0);
        white_output_time.draw(window, time_white);
        black_output_time.draw(window, time_black);
        /*
        sf::RectangleShape rectangle1(sf::Vector2f(150, 50));
        rectangle1.setFillColor(sf::Color(0, 0, 0));
        rectangle1.setPosition(700, 100);
        window.draw(rectangle1);
        sf::RectangleShape rectangle2(sf::Vector2f(150, 50));
        rectangle2.setFillColor(sf::Color(0, 0, 0));
        rectangle2.setPosition(700, 200);
        window.draw(rectangle2);*/
        for (int i = 0; i < 32; i++) {
            chees_pieces[i].draw(window);
        }
        Textend text;
        text.the_end(window, v);
        window.display();
    }

    return 0;
}