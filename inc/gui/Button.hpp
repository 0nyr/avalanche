#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button: sf::RectangleShape
{
    private:
        sf::IntRect box;
            sf::RectangleShape button;
        sf::Text text;

        int btnWidth;
        int btnHeight;

    public:
        Button(const sf::Vector2f & size = sf::Vector2f(0, 0));
        ~Button() = default;

        const bool IsClicked(
            const sf::Mouse Mouse, 
            const float X, 
            const float Y
        );

        void setFont(sf::Font &fonts);
        void setBackgroundColor(sf::Color color);
        void setTextColor(sf::Color color);
        
   
};