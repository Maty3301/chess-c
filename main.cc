#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Board.hh"
#include "include/UI.hh"

int main()
{
    Board board;
    sf::Vector2i posMouse;
    bool pressed = false;
    UI ui;
    bool jW, jB, jMW, jMB;
    sf::RenderWindow window(sf::VideoMode(504, 504), "Ajedrez");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            posMouse = sf::Mouse::getPosition(window);
            if (event.type == sf::Event::MouseButtonPressed)
                pressed = true;
            if (event.type == sf::Event::MouseButtonReleased)
                pressed = false;
        }

        board.Update(posMouse.x, posMouse.y, pressed);
        board.ConsultJaque(jW, jB, jMW, jMB);

        ui.Update(board.ConsultTurn());

        if (jW)
            ui.Jaque(true);
        if (jB)
            ui.Jaque(false);
        if (jMW)
            ui.JaqueMate(true);
        if (jMB)
            ui.JaqueMate(false);

        window.clear();
        window.draw(board);
        window.draw(ui);
        window.display();
    }

    exit(EXIT_SUCCESS);
}