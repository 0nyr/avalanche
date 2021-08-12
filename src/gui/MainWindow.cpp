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
                    100 + i*5 + i*20, 
                    100 + j*5 + j*20
                );
                window.draw(AliveCell);
            }
        }

        // end the current frame
        window.display();
}