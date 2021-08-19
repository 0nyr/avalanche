#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/** A virtual class for objects that have event response.
 */
class Eventable
{
    public:
        Eventable() = default;
        virtual ~Eventable() = default;
    
        // WARN: put "=0" for C++ to know it's pure virtual
        virtual void handleEvents(
            sf::RenderWindow & window,
            sf::Event & event
        ) = 0;
};