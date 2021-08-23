#pragma once

#include "../../inc/gui/UIObject.hpp"
#include "../../inc/app/AppSettings.hpp"
#include "../../inc/logic/Tickable.hpp"
#include "../../inc/utils/Array2D.hpp"


class Board: public UIObject, public Tickable
{
    private:
        sf::RenderWindow & window;

        // 2D array of pointers of cells
        // TODO make 2D array contiguous in memory
        // https://stackoverflow.com/questions/1768294/how-to-allocate-a-2d-array-of-pointers-in-c 
        Array2D<int> * cellMatrix;
        bool hasConverged;

        sf::FloatRect box;

        unsigned int tickCounter;
        unsigned int countEvolutions;
        unsigned int ticksForEvolution;

        void computeEvolutionOfCells();

    public:
        Board(
            sf::RenderWindow & window,
            sf::FloatRect box
        );
        ~Board();

        void tick();
        void handleEvents(
            sf::Event & event
        );
        void draw(
            sf::RenderTarget &target, sf::RenderStates states
        ) const;
};