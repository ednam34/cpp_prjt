#include "hpp/domino.hpp"
#include "hpp/dominoGrid.hpp"
#include "hpp/tuile.hpp"


Domino::Domino(){
    this->x = 0;
    this->y = 0;
    this->id = 0;
}


Domino::Domino(int x, int y, int id){
    this->x = x;
    this->y = y;
    this->id = id;
}


void Domino::setBorders(int n[4], int s[4], int e[4], int w[4]){
    for(int i = 0; i < 3; i++){
        this->n[i] = n[i];
        this->s[i] = s[i];
        this->e[i] = e[i];
        this->o[i] = w[i];
    }
}


void Domino::setX(int x){
    this->x = x;
}

void Domino::setY(int y){
    this->y = y;
}

void Domino::setID(int id){
    this->id = id;
}

int Domino::getX(){
    return x;
}

int Domino::getY(){
    return y;
}

int Domino::getID(){
    return id;
}

