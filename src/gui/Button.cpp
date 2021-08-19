#include "../../inc/gui/Button.hpp"
#include <string>

Button::Button(
    sf::RenderWindow & window,
    sf::FloatRect box, // WARN: don't put default in implementation
    sf::Text * text,
    sf::Font * font,
    sf::Color textColor,
    sf::Color bgColor,
    sf::Color borderColor,
    sf::Color bgHoverColor,
    sf::Color borderHoverColor,
    sf::Color bgClickColor,
    sf::Color borderClickColor
):  window(window), box(box), text(text), font(font),
    textColor(textColor), bgColor(bgColor), borderColor(borderColor),
    bgHoverColor(bgHoverColor), borderHoverColor(borderHoverColor),
    bgClickColor(bgClickColor), borderClickColor(borderClickColor)
{
    this->hasBeenRecentlyClicked = false;

    this->rectContainer = sf::RectangleShape(
        sf::Vector2f(this->box.width, this->box.height)
    );

    // apply font to text (WARN: do it first)
    this->text->setFont(*(this->font));

    // set colors and borders
    this->rectContainer.setOutlineThickness(4.f);
    this->rectContainer.setOutlineColor(this->borderColor);
    this->rectContainer.setFillColor(this->bgColor);
    this->text->setFillColor(this->textColor);


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

const bool Button::isClicked(
    sf::Mouse::Button mouseButton
)
{
    const sf::Mouse Mouse = sf::Mouse();
    // We check if it's clicked first because a direct value
    // comparison is less resource intensive than an area check
    if(!Mouse.isButtonPressed(mouseButton)){return false;}
    //It's pressed! Let's check it's actually in the box:
    return this->box.contains(
        Mouse.getPosition(this->window).x,
        Mouse.getPosition().y
    );
}

void Button::tick()
{
    // handle click animation
    if(this->hasBeenRecentlyClicked)
    {
        sf::Time timeSinceLastClick = this->clock.getElapsedTime();
        if(timeSinceLastClick.asSeconds() < 0.3)
        {
            // update graphics
            //sf::Color tmpColor = this->bgColor + (this->bgClickColor)*sf::Color(0xff*(1/this->clock.getElapsedTime().asSeconds()));
            sf::Color tmpColor;
            tmpColor.r = std::max(float(this->bgColor.r), this->bgClickColor.r*(1/this->clock.getElapsedTime().asSeconds()));
            tmpColor.g = std::max(float(this->bgColor.g), this->bgClickColor.g*(1/this->clock.getElapsedTime().asSeconds()));
            tmpColor.b = std::max(float(this->bgColor.b), this->bgClickColor.b*(1/this->clock.getElapsedTime().asSeconds()));
            this->rectContainer.setFillColor(tmpColor);
        }
        else
        {
            // reset click
            this->hasBeenRecentlyClicked = false;
            this->rectContainer.setFillColor(this->bgColor);
            std::cout << "reset timer\n";
        }
    }
}

void Button::handleEvents(
    sf::Event & event
)
{   
    switch (event.type)
    {
        // handle button hover event
        case sf::Event::MouseMoved:
        {   
            if(!this->hasBeenRecentlyClicked)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(
                    this->window
                );
                sf::Vector2f mousePosF(
                    static_cast<float>(mousePos.x), 
                    static_cast<float>(mousePos.y)
                );
                if(this->box.contains(mousePosF))
                {
                    // hover
                    this->rectContainer.setFillColor(
                        this->bgHoverColor);
                    this->rectContainer.setOutlineColor(
                        this->borderHoverColor);
                }
                else
                {
                    // not hover
                    this->rectContainer.setFillColor(
                        this->bgColor);
                    this->rectContainer.setOutlineColor(
                        this->borderColor);
                }
            }
            break;
        }
        // handle button click event
        case sf::Event::MouseButtonPressed:
        {
            // left click
            sf::Vector2i mousePos = sf::Mouse::getPosition(
                this->window);
            sf::Vector2f mousePosF(
                static_cast<float>(mousePos.x), 
                static_cast<float>(mousePos.y)
            );
            if(this->box.contains(mousePosF))
            {
                // clicked!
                this->hasBeenRecentlyClicked = true;
                this->clock.restart();

                // update display
                this->rectContainer.setFillColor(
                    this->bgClickColor);
                this->rectContainer.setOutlineColor(
                    this->borderClickColor);
            }
        }

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

