#pragma once

#include <list>
#include <iostream>
#include <thread>
#include <chrono>
#include "SFML/Graphics.hpp"
#include "../../inc/gui/UIObject.hpp"
#include "../../inc/gui/Button.hpp"
#include "../../inc/utils/ColorScheme.hpp"
#include "../../inc/app/AppSettings.hpp"
#include "../../inc/utils/Constants.hpp"
#include "../../inc/logic/KeyEventsManager.hpp"

class App 
{
    public:
        App();
        ~App();

        void run();

    private:
        sf::RenderWindow window;

        std::list<sf::Drawable *> drawables;
        std::list<UIObject *> uiObjects;
        KeyEventManager * keyEventManager;

        sf::Clock clock;

        // game loop methods
        void tick();
        void event();
        void render();

        void stop();

        sf::Uint64 getTime();

        // NOTE: Template methods need to be defined and declared inside .hpp file
        template<typename T>
        void handleEvents(std::list<T *> eventables, sf::Event event)
        {
            for (Eventable * eventable : eventables) {
                eventable->handleEvents(event);
            }
        }
        

    

};