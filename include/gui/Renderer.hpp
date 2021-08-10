#pragma once

#include <SFML/Graphics.hpp>

class Renderer{
    private:
        sf::RenderWindow &window;
        Plane &gamePlane;
        sf::RectangleShape AliveCell;
        void clearWindow();
        void renderCells();
        void drawGrid();
        void displayIt();
    public:
        Renderer(Plane&, sf::RenderWindow&);
        ~Renderer() = default;
        void render();
};