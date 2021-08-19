#include "../../inc/app/App.hpp"

App::App() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
    this->eventHandler = new EventHandler(this->window);

    // [ add graphical elements to this->drawables ] 
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

    // [ add UIObjects ]
    // add a Button
    sf::Font * fontButton = new sf::Font();
    fontButton->loadFromFile("./res/Minecraftia-Regular.ttf");
    sf::Text * text = new sf::Text();
    text->setString("PLAY");
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Blue);
    Button * textButton = new Button(
        window,
        sf::FloatRect(10, 10, 200, 100),
        text,
        fontButton
    );
    textButton->setBackgroundColor(sf::Color::Cyan);
    this->uiObjects.push_back(textButton);

}

App::~App()
{
    delete this->eventHandler;

    // delete lists of pointers using .erase(begin, end)
    this->drawables.erase(this->drawables.begin(), this->drawables.end());
    this->uiObjects.erase(this->uiObjects.begin(), this->uiObjects.end());
    
}

void App::gameLoop() 
{
    // run the program as long as the window is open
    while (window.isOpen())
    {
        this->tick();
        this->eventHandler->handleEvents(this->uiObjects);
        this->render();
    }
}

void App::tick()
{
    for(UIObject * uiObject : uiObjects)
    {
        if(dynamic_cast<Tickable *>(uiObject))
        {
            dynamic_cast<Tickable *>(uiObject)->tick();
        }
    }
}

void App::render()
{
    // clear the window with black color
    window.clear(sf::Color(ColorScheme::WINDOW_BG_GREY));

    // draw drawables first
    for(sf::Drawable * const& drawable : this->drawables) 
    {
        window.draw(*drawable);
    }

    // draw ioObjects next
    for(UIObject * const& uiObject : this->uiObjects) 
    {
        window.draw(*uiObject);
    }

    // end the current frame
    window.display();

}