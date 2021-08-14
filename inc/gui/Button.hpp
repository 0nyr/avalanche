#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../inc/gui/UIObject.hpp"

class Button: public UIObject
{
    private:
        sf::IntRect box;
        sf::RectangleShape rectContainer;

        // text and font must still exist to be used
        sf::Text * text;
        sf::Font * font;

    public:
        Button(
            sf::IntRect box = sf::IntRect(0, 0, 0, 0),
            sf::Text * text = new sf::Text(),
            sf::Font * font = new sf::Font()
        );
        ~Button();

        const bool IsClicked(
            const sf::Mouse Mouse, 
            const float X, 
            const float Y
        );

        void handleEvents();
        void draw(
            sf::RenderTarget &target, sf::RenderStates states
        ) const;

        void setFont(sf::Font * font)
        {
            this->font = font;
        }

        void setBackgroundColor(const sf::Color &color)
        {
            this->rectContainer.setFillColor(color);
        }

        void setTextColor(const sf::Color &color)
        {
            this->text->setFillColor(color);
        }

        void setString(const sf::String &string)
        {
            this->text->setString(string);
        }

        void setCharacterSize(unsigned int size)
        {
            this->text->setCharacterSize(size);
        }

        void setPosition(int x, int y);
        
};