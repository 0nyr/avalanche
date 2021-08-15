#include "../../inc/gui/MainWindow.hpp"

#include <iostream>
#include "../../inc/gui/Button.hpp"

MainWindow::MainWindow() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
    this->eventHandler = new EventHandler(this->window);
    this->renderer = new MainRenderer(this->window);

    // [ add graphical elements ]
    // add a circle
    sf::CircleShape * testCircle = new sf::CircleShape(70.f);
    testCircle->setFillColor(sf::Color::Green);
    testCircle->setPosition(600, 100);
    this->drawables.push_back(testCircle);

    // add a Rectangle
    sf::RectangleShape * testRect = new sf::RectangleShape(
        sf::Vector2f(100, 100)
    );
    testRect->setPosition(200, 600);
    this->drawables.push_back(testRect);

    // add a Button
    sf::Font * fontButton = new sf::Font();
    fontButton->loadFromFile("./res/Minecraftia-Regular.ttf");
    sf::Text * text = new sf::Text();
    text->setString("TESTBUTTON");
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Blue);
    Button * textButton = new Button(
        sf::IntRect(500, 550, 200, 100),
        text,
        fontButton
    );
    textButton->setBackgroundColor(sf::Color::Cyan);
    this->drawables.push_back(textButton);

}

MainWindow::~MainWindow()
{
    delete this->eventHandler;
    delete this->renderer;
    this->drawables.clear();
    
}

void MainWindow::gameLoop() 
{
    // run the program as long as the window is open
    while (window.isOpen())
    {
        this->eventHandler->handleEvents();
        this->renderer->render(drawables);
    }
}