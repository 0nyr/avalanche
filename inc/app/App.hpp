#pragma once

#include <list>
#include <iostream>
#include <thread>
#include <chrono>
#include "SFML/Graphics.hpp"
#include "../../inc/gui/UIObject.hpp"
#include "../../inc/gui/Button.hpp"
#include "../../inc/logic/EventHandler.hpp"
#include "../../inc/utils/ColorScheme.hpp"
#include "../../inc/app/AppSettings.hpp"
#include "../../inc/utils/Constants.hpp"

class App 
{
    private:
        sf::RenderWindow window;
        EventHandler * eventHandler;

        std::list<sf::Drawable *> drawables;
        std::list<UIObject *> uiObjects;

        sf::Clock clock;

        void tick();
        void render();

        void stop();

        sf::Uint64 getTime();

    public:
        App();
        ~App();

        void run();

};