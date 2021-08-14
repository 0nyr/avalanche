#include "../../inc/logic/MainRenderer.hpp"
#include <iostream>

MainRenderer::MainRenderer(
    sf::RenderWindow & window
): window(window)
{}

void MainRenderer::render(std::list<sf::Drawable *> & drawables)
{
    // clear the window with black color
    window.clear(sf::Color::Black);



    // create a 500x500 render-texture
    sf::RenderTexture renderTexture;
    renderTexture.create(500, 500);
    renderTexture.clear(sf::Color::Blue);

    // draw cells here
    sf::RectangleShape AliveCell = sf::RectangleShape(
        sf::Vector2f(5, 5)
    );
    AliveCell.setOutlineColor(sf::Color(100, 100, 100));
    AliveCell.setFillColor(sf::Color::White);
    AliveCell.setOutlineThickness(1.f);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            AliveCell.setPosition(
                i*5 + i*20, 
                j*5 + j*20
            );
            renderTexture.draw(AliveCell);
        }
    }

    // We're done drawing to the texture
    renderTexture.display();

    // get the target texture (where the stuff has been drawn)
    const sf::Texture& texture = renderTexture.getTexture();
    sf::Sprite sprite(texture);
    window.draw(sprite);



    // font test
    sf::Text text;

    // select the font
    sf::Font font;
    //font.loadFromFile("./res/slkscr.ttf");
    font.loadFromFile("./res/Minecraftia-Regular.ttf");
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("PAUSE");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setPosition(600, 600);

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);



    // button test
    sf::IntRect buttonBox = sf::IntRect(400, 300, 200, 100);

    // draw box
    sf::RectangleShape buttonShape = sf::RectangleShape(
        sf::Vector2f(buttonBox.width, buttonBox.height)
    );
    buttonShape.setFillColor(sf::Color::Yellow);
    buttonShape.setPosition(
        buttonBox.left,
        buttonBox.top
    );
    window.draw(buttonShape);
    
    // draw text
    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("BUTTON");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Red);
    buttonText.setPosition(
        buttonBox.left + buttonBox.width/2 - buttonText.getLocalBounds().width/2,
        buttonBox.top + buttonBox.height/2 - buttonText.getLocalBounds().height/2
    );
    window.draw(buttonText);



    // display drawables
    for (sf::Drawable * const& drawable : drawables) {
        window.draw(*drawable);
    }


    // end the current frame
    window.display();
}