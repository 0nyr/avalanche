#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/** Abstract UI object that can be rendered to a window
 * It can also react to events.
 * 
 *     sf::Drawable: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php 
 */
class UIObject: public sf::Drawable
{
    public:
        UIObject() = default;
        virtual ~UIObject() = default;
    
        // WARN: put "=0" for C++ to know it's pure virtual
        virtual void handleEvents() = 0;
        virtual void draw(
            sf::RenderTarget &target, sf::RenderStates states
        ) const = 0; // inherited from sf::Drawable

};