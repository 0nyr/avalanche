#pragma once

#include <list>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../inc/gui/UIObject.hpp"
#include "../../inc/gui/Button.hpp"
#include "../../inc/logic/EventHandler.hpp"
#include "../../inc/utils/ColorScheme.hpp"

class App 
{
    private:
        sf::RenderWindow window;
        EventHandler * eventHandler;

        std::list<sf::Drawable *> drawables;
        std::list<UIObject *> uiObjects;

        void tick();
        void render();

    public:
        App();
        ~App();

        void gameLoop();

};