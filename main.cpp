#include "hpp/dominoGrid.hpp"
#include "hpp/domino.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


int main()
{
    //create 10x10 random domino and put them in a vector
    std::vector<Domino> dominos;
    for(int i = 0; i < 100; i++){
        int x = rand() % 7;
        int y = rand() % 7;
        Domino domino(x, y, i);
        dominos.push_back(domino);
    }

    DominoGrid dg(10, 10);
    dg.setTuiles(dominos);
    dg.afficher();
}