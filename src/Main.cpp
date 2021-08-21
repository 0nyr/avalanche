#include <iostream>

#include <SFML/Graphics.hpp>

#include "../inc/app/App.hpp"

int main()
{
    // WARN: Don't confuse object with pointers of objects
    // https://stackoverflow.com/questions/14803570/non-class-type-error-in-c 
    App mainWindow;
    mainWindow.run();

    return 0;
}
