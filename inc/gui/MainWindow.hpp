#pragma once

#include "SFML/Graphics.hpp"
#include "../../inc/logic/MainRenderer.hpp"

class MainWindow {
    private:
        sf::RenderWindow window;
        MainRenderer * renderer;

        sf::CircleShape shape;

        void rendering();

    public:
        MainWindow();
        ~MainWindow();

        void gameLoop();
};