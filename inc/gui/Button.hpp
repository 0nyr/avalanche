#pragma once

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "../../inc/gui/UIObject.hpp"
#include "../../inc/utils/ColorScheme.hpp"
#include "../../inc/logic/Tickable.hpp"

class Button: public UIObject, public Tickable
{
    private:
        sf::RenderWindow & window;
        sf::Clock clock;
        bool hasBeenRecentlyClicked;

        sf::FloatRect box;
        sf::RectangleShape rectContainer;

        // text and font must still exist to be used
        sf::Text * text;
        sf::Font * font;

        // colors
        sf::Color textColor;
        sf::Color bgColor;
        sf::Color borderColor;

        sf::Color bgHoverColor;
        sf::Color borderHoverColor;

        sf::Color bgClickColor;
        sf::Color borderClickColor;

    public:
        Button(
            sf::RenderWindow & window,
            sf::FloatRect box,
            sf::Text * text,
            sf::Font * font,
            sf::Color textColor = sf::Color(ColorScheme::TEXT_WHITE),
            sf::Color bgColor = sf::Color(ColorScheme::BG_NORMAL_DARK_GREY),
            sf::Color borderColor = sf::Color(ColorScheme::BORDER_NORMAL),
            sf::Color bgHoverColor = sf::Color(ColorScheme::BG_HOVER_GREY),
            sf::Color borderHoverColor = sf::Color(ColorScheme::BORDER_HOVER_GREY),
            sf::Color bgClickColor = sf::Color(ColorScheme::BG_CLICK_GREY),
            sf::Color borderClickColor = sf::Color(ColorScheme::BORDER_CLICK_GREY)
        );
        ~Button();

        const bool isClicked(
            sf::Mouse::Button mouseButton = sf::Mouse::Left
        );

        void tick();
        void handleEvents(
            sf::Event & event
        );
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