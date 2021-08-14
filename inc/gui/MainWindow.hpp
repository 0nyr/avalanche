#pragma once

#include <list>
#include "SFML/Graphics.hpp"
#include "../../inc/logic/EventHandler.hpp"
#include "../../inc/logic/MainRenderer.hpp"
#include "../../inc/gui/UIObject.hpp"

class MainWindow {
    private:
        sf::RenderWindow window;
        EventHandler * eventHandler;
        MainRenderer * renderer;

        std::list<sf::Drawable *> drawables;

        void rendering();

    public:
        MainWindow();
        ~MainWindow();

        void gameLoop();
};