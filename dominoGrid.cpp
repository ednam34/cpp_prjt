#include "hpp/dominoGrid.hpp"



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

void DominoGrid::afficher(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            std::cout << tuiles[i][j]->getID() << " ";
        }
        std::cout << std::endl;
    }
}