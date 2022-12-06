#ifndef DOMINOGRID_HPP
#define DOMINOGRID_HPP

#include <iostream>
#include <string>
#include <vector>
#include "domino.hpp"
#include "grille.hpp"

class DominoGrid: public Grille{
    public:
        DominoGrid();
        DominoGrid(int height, int width);
        void setHeight(int height);
        void setWidth(int width);
        int getHeight();
        int getWidth();
        Domino getTuile(int i, int j);
        void generateBorders();
        void setDominoBorders();
        void setGrille();
        void setTuiles(std::vector<Domino>& dominos);
        bool putDomino(int x, int y, Domino& domino);
        void setTuileOnGrid(int x, int y, Domino domino);
        void afficher();
       //Domino* tuiles[7][7];

    protected:
        std::vector<Border> borders;
        std::vector<std::vector<Domino>> tuiles;
        //Domino* tuiles[7][7];
};






#endif