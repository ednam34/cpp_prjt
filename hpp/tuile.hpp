//def tuille.hpp
#ifndef TUILE_HPP
#define TUILE_HPP

#include <iostream>
#include <string>
#include <vector>


class Tuile
{
    public:
        Tuile();
        virtual void setX(int x) = 0;
        virtual void setY(int y) = 0;
        virtual void setID(int id) = 0;
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual int getID() = 0;
    
    protected:
        int x;
        int y;
        int id;

};









#endif