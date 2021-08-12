#include "../../inc/gui/MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow() {
    this->text = "Hello world";
}

void MainWindow::DisplayLoop() {
    std::cout << this->text << std::endl;
}