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
        void setTuiles(std::vector<Domino> dominos);
        void afficher();

    protected:
        Tuile* tuiles[10][10];
};






#endif