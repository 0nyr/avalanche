#include "../../inc/gui/MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
    this->renderer = new MainRenderer(this->window);
}

MainWindow::~MainWindow()
{
    delete this->renderer;
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
        this->renderer->render();
    }
}