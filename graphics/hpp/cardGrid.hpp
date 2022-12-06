#ifndef CARDGRID_HPP
#define CARDGRID_HPP


#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <array>
#include <tgmath.h>
#include "card.hpp"
#include "../../hpp/dominoGrid.hpp"

class CardGrid : public sf::Drawable
{
    public:
        std::vector<Card> cards;
        CardGrid();
        CardGrid(int rows, int cols,DominoGrid& dominoGrid);
        Card cardTest;
        //Card card;
        //~CardGrid();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void myDraw(sf::RenderTarget& target, sf::RenderStates states);
        Card getCard(int i);
        DominoGrid getDominoGrid();
        void setCard(int i, int j, int x, int y);
    protected:
        int rows;
        int cols;
        DominoGrid dominoGrid;
        
};



#endif