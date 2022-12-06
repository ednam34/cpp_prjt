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

CardGrid::CardGrid(int rows, int cols, DominoGrid& dominoGrid){
        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cards.push_back(Card(1, 2, 3, 50, 50));
            }
        }*/
        cards.push_back(Card(1, 2, 3, 50, 50));
        cardTest = Card(1, 2, 3, 50, 50);
        this->dominoGrid = dominoGrid;
        this->dominoGrid.afficher();
    }

Card CardGrid::getCard(int i)
    {
        return this->cardTest;
    }

DominoGrid CardGrid::getDominoGrid()
    {
        return this->dominoGrid;
    }

void CardGrid::setCard(int i, int j, int x, int y)
    {
        Domino domino = dominoGrid.getTuile(i,j);
        cards[i] = Card(domino, x,y);
    }

void CardGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        //print hello world
        //target.draw(cards[0]);
        //std::cout << "Hello World!" << std::endl;
        Border border(1, 2, 5);
        Border border2(4, 7, 5);
        Border border3(1, 2, 2);
        Border border4(6, 2, 8);

        
         for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                //Domino domino = dominoGrid.getTuiles()[i][j];
                //domino.setBorders(border, border2, border3, border4);
                //Card(domino, 72*j, 72*i).draw(target, states);
                /*this->setCard(i, j, 72*j, 72*i);
                Card(getDominoGrid().getTuiles()[i][j], 72*j, 72*i).draw(target, states);
                target.draw(Card(dominoGrid.getTuiles()[i][j], 72*j, 72*i)); */
            }
        }
}

void CardGrid::myDraw (sf::RenderTarget& target, sf::RenderStates states)
{
        //std::cout << "Hello World!" << std::endl;
        for (int i = 0; i < 7; i++)
        {
            //print hello world for test


            for (int j = 0; j < 7; j++)
            {
                //std::cout << "Hello World!" << std::endl;
                //dominoGrid.afficher();
                target.draw(Card(dominoGrid.getTuile(i,j), 72*j, 72*i));
            }
        }
}
