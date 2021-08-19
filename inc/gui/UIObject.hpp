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
};