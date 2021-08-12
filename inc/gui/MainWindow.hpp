#pragma once

#include "SFML/Graphics.hpp"

class MainWindow {
    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        void rendering();

    public:
        MainWindow();
        ~MainWindow() = default;

        void gameLoop();
};