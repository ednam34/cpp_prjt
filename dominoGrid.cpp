#include "hpp/dominoGrid.hpp"
#include <cstdlib>


DominoGrid::DominoGrid(){
    height = 0;
    width = 0;
}

DominoGrid::DominoGrid(int height, int width){
    this->height = height;
    this->width = width;
    //print height and width
    std::cout << "height: " << height << std::endl;
    std::cout << "width: " << width << std::endl;
}

void DominoGrid::setHeight(int height){
    this->height = height;
}

void DominoGrid::setWidth(int width){
    this->width = width;
}

int DominoGrid::getHeight(){
    return height;
}

int DominoGrid::getWidth(){
    return width;
}

void DominoGrid::generateBorders(){
    //generate 10 random borders and put them in a vector
    for(int i = 0; i < 10; i++){
        int x = rand() % 7;
        int y = rand() % 7;
        int z = rand() % 7;
        Border border(x,y,z);
        borders.push_back(border);
        border.afficher();
    }
}

void DominoGrid::setGrille(){
    //create a 10x10 grid of domino with -1 as id
    //Domino domino(0, 1, -1);
    int i = 0;
    int j = 0;
    for(int k = 0; k < 100; k++){
        this->tuiles[i][j] = new Domino(i,j, -1);
        j++;
        if(j == width){
            j = 0;
            i++;
        }
    }
}

void DominoGrid::setTuiles(std::vector<Domino> dominos){
    //take the vector of tuiles and put them in the 2d tuiles array
    int i = 0;
    int j = 0;
    for(int k = 0; k < dominos.size(); k++){
        this->tuiles[i][j] = &dominos[k];
        j++;
        if(j == width){
            j = 0;
            i++;
        }
    }
}

void DominoGrid::setTuileOnGrid(int x, int y, Domino domino){
    //put a domino on the grid
    this->tuiles[x][y] = &domino;
}

void DominoGrid::afficher(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            std::cout << tuiles[i][j]->getID() << " ";
        }
        std::cout << std::endl;
    }
}