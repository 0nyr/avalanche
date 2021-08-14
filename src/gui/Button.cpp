#include "../../inc/gui/Button.hpp"

Button::Button(
    sf::IntRect box, // WARN: don't put default in implementation
    sf::Text * text,
    sf::Font * font
): box(box), text(text)
{
    this->rectContainer = sf::RectangleShape(
        sf::Vector2f(this->box.width, this->box.height)
    );

    // center the text with respect to the box background
    this->text->setPosition(
        box.left + box.width/2 - text->getLocalBounds().width/2,
        box.top + box.height/2 - text->getLocalBounds().height/2
    );
    
}

Button::~Button(){}

void Button::setPosition(int x, int y)
{
    this->box.left = x;
    this->box.top = y;

    // update rectContainer
    this->text->setPosition(
        box.left + box.width/2 - text->getLocalBounds().width/2,
        box.top + box.height/2 - text->getLocalBounds().height/2
    );
}

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

void Button::handleEvents()
{
    //TODO: complete function
}

void Button::draw(
    sf::RenderTarget &target, sf::RenderStates states
) const
{
    // draw button box background
    target.draw(this->rectContainer, states);

    // draw text
    target.draw(*(this->text), states);
}

