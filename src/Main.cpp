#include <iostream>

#include <SFML/Graphics.hpp>

#include "../inc/gui/MainWindow.hpp"

int main()
{
    // WARN: Don't confuse object with pointers of objects
    // https://stackoverflow.com/questions/14803570/non-class-type-error-in-c 
    MainWindow mainWindow;
    mainWindow.DisplayLoop();

    return 0;
}
