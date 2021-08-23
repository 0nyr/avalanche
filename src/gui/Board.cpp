#include "../../inc/gui/Board.hpp"

Board::Board(sf::RenderWindow & window): window(window)
{
    this->tickCounter = 0;
    this->countEvolutions = 0;
    this->ticksForEvolution = 
        AppSettings::TICKS_PER_SEC/AppSettings::TICK_BOARD_PER_SEC;
}

Board::~Board()
{
    // TODO: don"t forget to destroy the matrix of cells
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
    this->countEvolutions++;

    // TODO: compute evolution
}

void Board::handleEvents(sf::Event & event)
{

}

void Board::draw(
    sf::RenderTarget &target, sf::RenderStates states
) const
{

}

