#include "../../inc/gui/Board.hpp"

#include <iostream>
#include "../SFML/Graphics.hpp"
#include "../../inc/app/AppSettings.hpp"
#include "../../inc/utils/ColorScheme.hpp"

Board::Board(
    sf::RenderWindow & window,
    sf::FloatRect box
): window(window), box(box)
{
    // init matrix of cells
    this->cellMatrix = new Array2D<int>(
        AppSettings::HEIGHT_CELL_NUMBER,
        AppSettings::WIDTH_CELL_NUMBER
    );
    this->hasConverged = false;
    // fill the center cell only
    this->cellMatrix->fill(0);
    this->cellMatrix->at(
        AppSettings::HEIGHT_CELL_NUMBER/2,
        AppSettings::WIDTH_CELL_NUMBER/2
    ) = 2000;

    this->tickCounter = 0;
    this->countEvolutions = 0;
    this->ticksForEvolution = 
        AppSettings::TICKS_PER_SEC/AppSettings::TICK_BOARD_PER_SEC;
}

Board::~Board()
{
    delete this->cellMatrix;
}

void Board::tick()
{
    this->tickCounter++;

    if(this->tickCounter >= this->ticksForEvolution)
    {
        this->computeEvolutionOfCells();
        this->tickCounter = 0;
    }

}

void Board::computeEvolutionOfCells()
{
    // in case convergence was reached, return
    if(this->hasConverged)
    {
        std::cout << "Convergence reached!" << std::endl;
        return;
    }
    this->hasConverged = true;

    this->countEvolutions++;

    /* If a cell z(x,y) where x and y are respectively line x and 
    column y, contains at least 4 flakes, it’s called unstable 
    and loses 4 flakes which switch to the four neighbouring cells,
    according to the rule:

        z(x,y) -> z(x,y) - 4
        z(x ±1,y) -> z(x ±1,y) + 1
        z(x,y ±1) -> z(x,y ±1) + 1

    If this cell is on the border, the flakes which should be 
    given to the neighbouring cells are lost. In this way every 
    unstable cell determines the evolution of the grid’s state. */
    for(int i = 0; i < this->cellMatrix->getHeight(); i++)
    {
        for(int j = 0; j < this->cellMatrix->getWidth(); j++)
        {
            int & cell = this->cellMatrix->at(i, j);
            if(cell >= 4)
            {
                // if first time modification, then convergence not reached
                if(this->hasConverged == true)
                    this->hasConverged = false;

                // apply rules
                cell -= 4;
                if(j - 1 >= 0)
                    this->cellMatrix->at(i, j - 1)++;
                if(j + 1 < this->cellMatrix->getWidth())
                    this->cellMatrix->at(i, j + 1)++;
                if(i - 1 >= 0)
                    this->cellMatrix->at(i - 1, j)++;
                if(i + 1 < this->cellMatrix->getHeight())
                    this->cellMatrix->at(i + 1, j)++;
            }
        }
    }
}

void Board::handleEvents(sf::Event & event)
{
    // TODO: add mouse support
}

void Board::draw(
    sf::RenderTarget &target, sf::RenderStates states
) const
{
    // TODO: finish and test function
    // compute cell height and width
    float cellWidth = this->box.width/AppSettings::WIDTH_CELL_NUMBER;
    float cellHeight = this->box.height/AppSettings::HEIGHT_CELL_NUMBER;
    float const gridSeparator = 2.f;

    for(int i = 0; i < this->cellMatrix->getHeight(); i++)
    {
        for(int j = 0; j < this->cellMatrix->getWidth(); j++)
        {
            int & cell = this->cellMatrix->at(i, j);

            sf::RectangleShape cellRect = sf::RectangleShape(
                sf::Vector2f(cellWidth, cellHeight)
            );
            cellRect.setPosition(
                sf::Vector2f(
                    this->box.top + (cellWidth + gridSeparator)*j,
                    this->box.left + (cellHeight + gridSeparator)*i
                )
            );

            // cell color
            if(cell <= 0)
            {
                cellRect.setFillColor(sf::Color(ColorScheme::CELL_LEVEL_0));
            }
            else if(cell == 1)
            {
                cellRect.setFillColor(sf::Color(ColorScheme::CELL_LEVEL_1));
            }
            else if(cell == 2)
            {
                cellRect.setFillColor(sf::Color(ColorScheme::CELL_LEVEL_2));
            }
            else if(cell == 3)
            {
                cellRect.setFillColor(sf::Color(ColorScheme::CELL_LEVEL_3));
            }
            else if(cell >= 4)
            {
                cellRect.setFillColor(sf::Color(ColorScheme::CELL_LEVEL_4));
            }
            
            target.draw(cellRect);
            
        }
    }

}

