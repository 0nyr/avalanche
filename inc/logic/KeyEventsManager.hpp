#pragma once

#include "../../inc/logic/Eventable.hpp"

class KeyEventManager: public Eventable
{
    private:
        sf::RenderWindow & window;

    public:
        KeyEventManager(sf::RenderWindow & window);
        ~KeyEventManager() = default;

        void handleEvents(sf::Event & event);

};
