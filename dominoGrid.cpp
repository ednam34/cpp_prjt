#include "hpp/dominoGrid.hpp"

#include <cstdlib>

DominoGrid::DominoGrid() {
    height = 0;
    width = 0;
}

DominoGrid::DominoGrid(int height, int width) {
    this->height = height;
    this->width = width;
    // print height and width
    std::cout << "height: " << height << std::endl;
    std::cout << "width: " << width << std::endl;
}

void DominoGrid::setHeight(int height) { this->height = height; }

void DominoGrid::setWidth(int width) { this->width = width; }

int DominoGrid::getHeight() { return height; }

int DominoGrid::getWidth() { return width; }

Domino DominoGrid::getNextDomino() { return nextDom; }

void DominoGrid::generateBorders() {
    srand((unsigned)time(NULL));
    // generate 10 random borders and put them in a vector
    for (int i = 0; i < 10; i++) {
        int x = rand() % 7;
        int y = rand() % 7;
        int z = rand() % 7;
        Border border(x, y, z);
        borders.push_back(border);
        border.afficher();
    }
}

void DominoGrid::generateNextDomino(){
    int x = rand() % 10;
    int y = rand() % 10;
    int z = rand() % 10;
    int w = rand() % 10;
    Domino domino(0, 0, 20);
    domino.setBorders(borders[x], borders[y], borders[z], borders[w]);
    this->nextDom = domino;
}


void DominoGrid::setDominoBorders() {
    // for each domino in Domino* tuiles[10][10] set random borders from the
    // vector borders
    int count = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = rand() % 10;
            int y = rand() % 10;
            int z = rand() % 10;
            int w = rand() % 10;           
            // dom.printBorders();
            this->tuiles[i][j].setBorders(borders[x], borders[y], borders[z],borders[w]);
            this->tuiles[i][j].setID(count);
            count++;
        }
    }
    std::cout << "domino borders set" << std::endl;
    getTuile(4, 4).printBorders();
}

void DominoGrid::setGrille() {
    // create a 10x10 grid of domino with -1 as id
    // Domino domino(0, 1, -1);
    this->generateBorders();

    for (int i = 0; i < height; i++) {
        std::vector<Domino> row;
        for (int j = 0; j < width; j++) {

            Border border(0, 0, 0);
            Domino domino(0, 1, 0);

            domino.setBorders(border, border, border, border);
            domino.setX(i*72);
            domino.setY(j*72);
            row.push_back(domino);
        }
        tuiles.push_back(row);
    }
}

void DominoGrid::setTuiles(std::vector<Domino>& dominos) {
    // take the vector of tuiles and put them in the 2d tuiles array
    int i = 0;
    int j = 0;
    for (int k = 0; k < dominos.size(); k++) {
        this->tuiles[i].push_back(dominos[k]);
    }
}

Domino DominoGrid::getTuile(int x, int y) { return tuiles[x][y]; }

Domino DominoGrid::getTuileXY(int x, int y) {
    // return the domino at the position x, y 
    for(int i=0; i<tuiles.size();i++){
        for(int j=0; j<tuiles[i].size();j++){
            if(x>tuiles[i][j].getX() && x<tuiles[i][j].getX()+72 && y>tuiles[i][j].getY() && y<tuiles[i][j].getY()+72){
                return tuiles[i][j];
            }
        }
    }
    return Domino(0,0,0);
}

bool DominoGrid::putDomino(int x, int y, Domino& domino) {
    // put a domino on the grid

    if (getTuile(x, y).getID() == 0 && getTuile(x + 1, y).getID() == 0 &&
        getTuile(x - 1, y).getID() == 0 && getTuile(x, y + 1).getID() == 0 &&
        getTuile(x, y - 1).getID() == 0) {
        this->tuiles[x][y] = domino;
        return true;
    } else {
        bool find = true;
        if (!getTuile(x + 1, y).getN().isEquals(domino.getS())) {
            find = false;
        }
        if (!getTuile(x - 1, y).getS().isEquals(domino.getN())) {
            find = false;
        }
        if (!getTuile(x, y + 1).getW().isEquals(domino.getE())) {
            find = false;
        }
        if (!getTuile(x, y - 1).getE().isEquals(domino.getW())) {
            find = false;
        }
        if (find) {
            this->tuiles[x][y] = domino;
            return true;
        }
        return false;
    }
}

void DominoGrid::setTuileOnGrid(int x, int y, Domino domino) {
    //print x and y of the tuile
    std::cout << "x: " << tuiles[x][y].getX() << " y: " << tuiles[x][y].getY() << std::endl;    
    domino.setX(this->tuiles[x][y].getX());
    domino.setY(this->tuiles[x][y].getY());
    this->tuiles[x][y] = domino;
    if (x > height || y > width) {
        std::cout << "Error: out of bounds" << std::endl;
    }
    if (this->putDomino(x, y, domino) == false) {
        std::cout << "Error: can't put domino on grid" << std::endl;
    } else {
        // this->tuiles[x][y] = domino;
    }
}



void DominoGrid::afficher() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << tuiles[i][j].getID() << " ";
        }
        std::cout << std::endl;
    }
}
