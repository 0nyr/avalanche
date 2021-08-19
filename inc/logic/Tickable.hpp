#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/** A virtual class for objects that have event response.
 */
class Tickable
{
    public:
        Tickable() = default;
        virtual ~Tickable() = default;
    
        // WARN: put "=0" for C++ to know it's pure virtual
        virtual void tick() = 0;
};