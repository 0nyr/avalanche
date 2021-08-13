#include "../../inc/gui/MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
}

void MainWindow::gameLoop() 
{
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        this->rendering();
    }
}

void MainWindow::rendering()
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
    


    // end the current frame
    window.display();
}