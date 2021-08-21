#include "../../inc/app/App.hpp"

App::App() 
{
    this->window.create(sf::VideoMode(1000, 1000), "Avalanche");
    this->keyEventManager = new KeyEventManager(this->window);

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
    delete this->keyEventManager;

    // delete lists of pointers using .erase(begin, end)
    this->drawables.erase(
        this->drawables.begin(), this->drawables.end()
    );
    this->uiObjects.erase(
        this->uiObjects.begin(), this->uiObjects.end()
    );
    
}

/** This function is contains the game loop. It runs as long
 * as the application runs.
 */
void App::run()
{   
    // run tick variables
    unsigned int ticks = 0;
    sf::Uint64 timeVar; // time length between two loops
    sf::Uint64 timer = 0; // total enlapsed time (max 1s)
    sf::Uint64 delta = 0; // enlapsed time since last active ticking
    double timePerTick = 
        Constants::MICROSECS_PER_SEC/double(AppSettings::TICKS_PER_SEC);
    sf::Uint64 currentTime;
    sf::Uint64 lastTime = this->getTime();
    

    // gameloop - run the program as long as the window is open
    while (window.isOpen())
    {
        currentTime = this->getTime();
        timeVar = currentTime - lastTime;
        timer += timeVar;
        delta += timeVar;
        lastTime = currentTime;

        // sleep to avoid saturating processor with computations
        try
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1ms);
        }
        catch(std::exception const & exc)
        {
            std::cout << 
                "[ERROR]: error while trying to sleep. " <<
                exc.what()
            << std::endl;
        } 

        if(delta/timePerTick >= 1)
        {
            // active ticking
            this->tick();
            this->event();
            this->render();

            ticks++;
            delta -= timePerTick;
        }

        if(timer >= Constants::MICROSECS_PER_SEC)
        {
            // VERB: log ticks/s
            std::cout << "Ticks/s: " << ticks << std::endl;

            ticks = 0;
            timer = 0;
        }
        
    }

    // ends program
    this->stop();
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

void App::event()
{
    // base event handling
    sf::Event event;
    while (window.pollEvent(event))
    {
        // check general events
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

        // handle events of objects & object lists
        this->handleEvents(this->uiObjects, event);
        this->keyEventManager->handleEvents(event);
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

/** Clear ressources before app ends.
 */
void App::stop()
{
    // TODO:finish method
}

/** Get curent time in microseconds.
 * OPTI: inline here, means to replace the function by its code
 */
inline sf::Uint64 App::getTime()
{
    return this->clock.getElapsedTime().asMicroseconds();
}