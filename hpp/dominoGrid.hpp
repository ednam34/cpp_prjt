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
        void generateBorders();
        void setGrille();
        void setTuiles(std::vector<Domino> dominos);
        void setTuileOnGrid(int x, int y, Domino domino);
        void afficher();

    protected:
        std::vector<Border> borders;
        Tuile* tuiles[10][10];
};






#endif