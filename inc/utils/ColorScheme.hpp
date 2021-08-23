#pragma once

#include "SFML/Graphics.hpp"

class ColorScheme
{
    public:
        // 0XRRGGBBAA R - Red, Green, Blue, Alpha
        static sf::Uint32 const WINDOW_BG_GREY = 0x414a59ff;
        static sf::Uint32 const CONTAINER_MEDIUM_GREY = 0x353e4dff;
        
        static sf::Uint32 const TEXT_WHITE = 0xd4d7deff;

        static sf::Uint32 const BG_NORMAL_DARK_GREY = 0x2e353eff;
        static sf::Uint32 const BORDER_NORMAL = 0x515f70ff;
        static sf::Uint32 const BG_HOVER_GREY = BORDER_NORMAL;
        static sf::Uint32 const BORDER_HOVER_GREY = TEXT_WHITE;
        static sf::Uint32 const BG_CLICK_GREY = 0x7b8c9fff;
        static sf::Uint32 const BORDER_CLICK_GREY = TEXT_WHITE;

        // cell colors
        static sf::Uint32 const CELL_LEVEL_0 = 0x213245ff;
        static sf::Uint32 const CELL_LEVEL_1 = 0x28415cff;
        static sf::Uint32 const CELL_LEVEL_2 = 0x2e5f7fff;
        static sf::Uint32 const CELL_LEVEL_3 = 0x3d8db8ff;
        static sf::Uint32 const CELL_LEVEL_4 = 0x6fbbd3ff;
};

