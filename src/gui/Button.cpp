#include "../../inc/gui/Button.hpp"
#include <string>

Button::Button(
    sf::IntRect box, // WARN: don't put default in implementation
    sf::Text * text,
    sf::Font * font
): box(box), text(text), font(font)
{
    this->rectContainer = sf::RectangleShape(
        sf::Vector2f(this->box.width, this->box.height)
    );

    // apply font to text
    this->text->setFont(*(this->font));

    // set position of internal shapes
    std::cout << "position this->box: [" << this->box.left << ", " << this->box.top << "]" << std::endl;
    
    this->rectContainer.setPosition(
        sf::Vector2f(this->box.left, this->box.top)
    );
    this->text->setPosition(
        box.left + box.width/2 - text->getLocalBounds().width/2,
        box.top + box.height/2 - text->getLocalBounds().height/2
    );
    std::cout << text->getLocalBounds().height/2 << std::endl;

    std::cout << "position this->text: [" << this->text->getPosition().x << ", " << this->text->getPosition().y << "]" << std::endl;
    std::cout << "this->text string: " << (std::string)(this->text->getString()) << std::endl; 

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

