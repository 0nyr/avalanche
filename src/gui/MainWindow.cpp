#include "../../inc/gui/MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
    this->eventHandler = new EventHandler(this->window);
    this->renderer = new MainRenderer(this->window);
}

MainWindow::~MainWindow()
{
    delete this->eventHandler;
    delete this->renderer;
}

void MainWindow::gameLoop() 
{
    // run the program as long as the window is open
    while (window.isOpen())
    {
        this->eventHandler->handleEvents();
        this->renderer->render();
    }
}