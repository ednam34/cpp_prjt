#include "hpp/domino.hpp"
#include "hpp/dominoGrid.hpp"
#include "hpp/tuile.hpp"


Border::Border(){
    a = 0;
    b = 0;
    c = 0;
}
Border::Border(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
}
void Border::update(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
}
int Border::getA(){
    return a;
}
int Border::getB(){
    return b;
}
int Border::getC(){
    return c;
}

void Border::afficher(){
    std::cout << a << " " << b << " " << c << std::endl;
}


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


void Domino::setBorders(Border n, Border e, Border s, Border w){
    this->n = n;
    this->e = e;
    this->s = s;
    this->w = w;
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

