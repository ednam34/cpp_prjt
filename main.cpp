#include "hpp/dominoGrid.hpp"
#include "hpp/domino.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "graphics/test.cpp"

void test(DominoGrid& dg)
{
     //print hello world
     

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Card");

    // Create a card with numbers 3, 4, 5, and 6
    //Card card(4, 5, 6, 40,40);
    CardGrid grid(1, 1, dg);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        // Draw the card on the screen
        //window.draw(card);
        grid.myDraw(window, sf::RenderStates::Default);
        //window.draw(text);
        window.display();

    }

}


int main()
{
    //create 10x10 random domino and put them in a vector
    srand((unsigned) time(NULL)); 
    std::vector<Domino> dominos;
    for(int i = 0; i < 70; i++){
        int x = rand() % 7;
        int y = rand() % 7;
        Domino domino(x, y, i);
        dominos.push_back(domino);
    }

    

    int x = rand() % 7;
    int y = rand() % 7;
    Domino domino(x, y, 3);


    DominoGrid dg(7, 7);
    std::cout << "hello There" << std::endl;
    dg.setGrille();
    std::cout << "hello There2" << std::endl;
    dg.afficher();
    dg.setTuileOnGrid(4, 4, domino);
    dg.setTuileOnGrid(4, 3, domino);
    std::cout << "-------------------" << std::endl;
    dg.afficher();
    //dg.setTuileOnGrid(4, 4, domino);
    dg.generateBorders();
    dg.setDominoBorders();
    test(dg);
}