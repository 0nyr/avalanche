#include "../../inc/logic/EventHandler.hpp"

EventHandler::EventHandler(
    sf::RenderWindow & window
): window(window)
{}

void EventHandler::handleEvents()
{
    // check all the window's events that were triggered 
    // since the last iteration of the loop
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
}