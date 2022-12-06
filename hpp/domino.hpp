#ifndef DOMINO_HPP
#define DOMINO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "tuile.hpp"

class Border{
    public:
        Border();
        Border(int a, int b, int c);
        void update(int a, int b, int c);
        int getA();
        int getB();
        int getC();
        bool isEquals(Border b);
        void afficher();
    protected:
        int a;
        int b;
        int c;    
};

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
        Border getN();
        Border getE();
        Border getS();
        Border getW();
        void setBorders(Border n, Border e, Border s, Border w);
        void printBorders();
    protected:
        Border n;
        Border s;
        Border e;
        Border w;
        




};
#endif