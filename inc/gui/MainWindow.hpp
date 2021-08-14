#pragma once

#include "SFML/Graphics.hpp"
#include "../../inc/logic/EventHandler.hpp"
#include "../../inc/logic/MainRenderer.hpp"

class MainWindow {
    private:
        sf::RenderWindow window;
        EventHandler * eventHandler;
        MainRenderer * renderer;

        sf::CircleShape shape;

        void rendering();

    public:
        MainWindow();
        ~MainWindow();

        void gameLoop();
};