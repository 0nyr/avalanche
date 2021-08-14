#pragma once

#include "SFML/Graphics.hpp"

/** This object basically manages all the events
 * 
 */
class EventHandler {
    private:
        sf::RenderWindow & window;

    public:
        EventHandler(sf::RenderWindow & window);
        ~EventHandler() = default;

        void handleEvents();
};