#ifndef DOMINO_HPP
#define DOMINO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "tuile.hpp"

class Domino: public Tuile{

    public:
        Domino();
        Domino(int x, int y, int id);
        void setX(int x);
        void setY(int y);
        void setID(int id);
        int getX();
        int getY();
        int getID();
        void setBorders(int n[4], int s[4], int e[4], int w[4]);
    protected:
        int n[3];
        int s[3];
        int e[3];
        int o[3];




};
#endif