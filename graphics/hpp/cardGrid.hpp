#ifndef CARDGRID_HPP
#define CARDGRID_HPP


#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <array>
#include <tgmath.h>
#include "card.hpp"


class CardGrid : public sf::Drawable
{
    public:
        std::vector<Card> cards;
        CardGrid();
        CardGrid(int rows, int cols);
        Card cardTest;
        //Card card;
        //~CardGrid();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        Card getCard(int i);
    protected:
        int rows;
        int cols;
        
};



#endif