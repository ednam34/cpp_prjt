#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "tuile.hpp"


class Grille{

    public:
        Grille();
        virtual void setHeight(int height) = 0;
        virtual void setWidth(int width) = 0;
        virtual int getHeight() = 0;
        virtual int getWidth() = 0;
        virtual void afficher() = 0;
    protected:
        int height;
        int width;
        //Tuile* tuiles[height][width];
        //std::vector<Tuile *> tuiles;
};


#endif