#include "hpp/cardGrid.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <array>
#include <tgmath.h>
#include "hpp/card.hpp"

CardGrid::CardGrid(){
        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cards.push_back(Card(1, 2, 3, 50, 50));
            }
        }*/
        cards.push_back(Card(1, 2, 3, 50, 50));
        //card = Card(1, 2, 3, 50, 50);
}

CardGrid::CardGrid(int rows, int cols){
        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cards.push_back(Card(1, 2, 3, 50, 50));
            }
        }*/
        cards.push_back(Card(1, 2, 3, 50, 50));
        cardTest = Card(1, 2, 3, 50, 50);
    }

Card CardGrid::getCard(int i)
    {
        return this->cardTest;
    }

void CardGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        //print hello world
        //target.draw(cards[0]);
        //std::cout << "Hello World!" << std::endl;
        
        
         for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Card(1, 2, 3, 72*j, 72*i).draw(target, states);
            }
        }
}
