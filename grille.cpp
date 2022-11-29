//inckude "grille.h"


// Path: grille.cpp

#include "hpp/grille.hpp"
#include <iostream>
#include <chrono>
#include <thread>

grille::grille()
{
    //ctor
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            tuiles.push_back(Tuile(i*50,j*50,0));
        }
    }
}

grille::grille(std::vector<Tuile> tuiles, int gameType)
{
    this->tuiles = tuiles;
    this->gameType = gameType;
}

grille::grille(std::vector<Domino> dominos, int gameType)
{
    this->setTuiles(dominos);
    this->gameType = gameType;
}


grille::~grille()
{
    //dtor
}


void grille::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0; i < tuiles.size(); i++)
    {
        
        target.draw(tuiles[i]);
    
        //draw the tuiles casted as domino


        target.draw(tuiles[i]);

        //tuiles[i].drawText(target,states,i);
    }
}

//settuiles
void grille::setTuiles(std::vector<Domino> dominos)
{
    std::vector<Tuile> temp;
    for(int i = 0; i < dominos.size(); i++)
    {
        temp.push_back(dominos[i]);
    }
    this->tuiles = temp;
}

Tuile grille::getTuile(int x, int y)
{
    for(int i = 0; i < tuiles.size(); i++)
    {
        if(x > tuiles[i].getX() && x < tuiles[i].getX()+50)
        {
            if(y > tuiles[i].getY() && y < tuiles[i].getY()+50)
            {
                std::cout << "tuile found" << std::endl;
                std::cout << i << std::endl;
                tuiles[i].changeColor();
                //std::this_thread::sleep_for(std::chrono::milliseconds(200));
                return tuiles[i];
                
            }
        }
    }
    return tuiles[0];   
}