#include <iostream>

#include <SFML/Graphics.hpp>

#include "../inc/gui/MainWindow.hpp"

int main()
{
    MainWindow mainWindow = MainWindow();
    mainWindow.DisplayLoop();

    return 0;
}
