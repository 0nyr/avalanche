#pragma once

#include "SFML/Graphics.hpp"

class MainWindow {
    private:
        sf::Window window;
        sf::CircleShape shape;

    public:
        MainWindow();
        ~MainWindow() = default;
        void DisplayLoop();
};