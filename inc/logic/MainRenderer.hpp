#pragma once

#include "SFML/Graphics.hpp"

/** This object basically manages all the graphics
 * 
 */
class MainRenderer {
    private:
        sf::RenderWindow & window;

    public:
        MainRenderer(sf::RenderWindow & window);
        ~MainRenderer() = default;

        void render();
};