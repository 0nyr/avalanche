#include "../../inc/gui/Button.hpp"

const bool Button::IsClicked(
    const sf::Mouse Mouse, const float x, const float y
)
{
    // We check if it's clicked first because a direct 
    // value comparison is less resource intensive than an area check
    if(!Mouse.isButtonPressed(sf::Mouse::Left)){return false;}
    //It's pressed! Let's check it's actually in the box:
    return this->box.contains(x, y);
}

