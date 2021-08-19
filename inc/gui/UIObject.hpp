#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../inc/logic/Eventable.hpp"

/** A virtual class for objects that are both
 * sf::Drawable and Eventable.
 */
class UIObject: public sf::Drawable, public Eventable
{
    public:
        UIObject() = default;
        virtual ~UIObject() = default;
    
        // inherited virtual funtions:
        virtual void handleEvents(
            sf::RenderWindow & window,
        sf::Event & event
        ) = 0;
        
        virtual void draw(
            sf::RenderTarget &target, sf::RenderStates states
        ) const = 0; // inherited from sf::Drawable
};