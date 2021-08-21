#include "../../inc/logic/KeyEventsManager.hpp"

KeyEventManager::KeyEventManager(
    sf::RenderWindow & window
): window(window)
{}

void KeyEventManager::handleEvents(sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        // ECHAP key
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
            {
                std::cout << 
                    "[INFO] The escape key was pressed. " <<
                    "Terminating program..." 
                << std::endl;
                this->window.close();
                break;
            }
        }
    }
}