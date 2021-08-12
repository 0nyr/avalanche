#pragma once

#include <string>

class MainWindow {
    private:
    std::string text;

    public:
        MainWindow();
        ~MainWindow() = default;
        void DisplayLoop();
};