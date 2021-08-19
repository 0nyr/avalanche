#include "../../inc/gui/Button.hpp"
#include <string>

Button::Button(
    sf::FloatRect box, // WARN: don't put default in implementation
    sf::Text * text,
    sf::Font * font
): box(box), text(text), font(font)
{
    this->rectContainer = sf::RectangleShape(
        sf::Vector2f(this->box.width, this->box.height)
    );

    // apply font to text (WARN: do it first)
    this->text->setFont(*(this->font));

    // set position of internal shapes
    this->rectContainer.setPosition(
        sf::Vector2f(this->box.left, this->box.top)
    );

    sf::FloatRect textRect = text->getLocalBounds();
    this->text->setOrigin(
        textRect.left + textRect.width/2.0f,
        textRect.top + textRect.height/2.0f
    );
    this->text->setPosition(
        this->box.left + this->box.width/2.0f,
        this->box.top + this->box.height/2.0f
    );
}

Button::~Button(){
    delete this->text;
    delete this->font;
}

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

void Button::handleEvents(
    sf::RenderWindow & window,
    sf::Event & event
)
{
    // handle button hover event
    switch (event.type)
    {
        case sf::Event::MouseMoved:
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition( window );
            sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            if(this->box.contains(mousePosF))
            {
                // hover
                this->rectContainer.setFillColor( sf::Color( 200, 200, 100));
            }
            else
            {
                this->rectContainer.setFillColor(sf::Color(100, 100, 50));
            }
        }
        break;
    }

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

