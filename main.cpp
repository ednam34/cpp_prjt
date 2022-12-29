#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "graphics/test.cpp"
#include "hpp/domino.hpp"
#include "hpp/dominoGrid.hpp"
#include "hpp/mainScreen.hpp"


void test(DominoGrid& dg) {
    // print hello world

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Card");

    int test = mainMenuFunc(window);

    if(test == 3) {
        window.clear();
        CardGrid grid(1, 1, dg);
        while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //window.clear();

        // Draw the card on the screen
        // window.draw(card);
        grid.myDraw(window, sf::RenderStates::Default);
        grid.UpdateNextCard(window, sf::RenderStates::Default);
        // window.draw(text);
        window.display();

        // Draw objects to the window here...

        // Display the updated window on the screen
        window.display();
    }
    }

    // Create a card with numbers 3, 4, 5, and 6
    // Card card(4, 5, 6, 40,40);
    /*CardGrid grid(1, 1, dg);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw the card on the screen
        // window.draw(card);
        grid.myDraw(window, sf::RenderStates::Default);
        grid.UpdateNextCard(window, sf::RenderStates::Default);
        // window.draw(text);
        window.display();

        window.clear();

        // Draw objects to the window here...

        // Display the updated window on the screen
        window.display();
    }*/
}

int main() {
    // create 10x10 random domino and put them in a vector
    

    srand((unsigned)time(NULL));
    
    int x = rand() % 7;
    int y = rand() % 7;
    Domino domino(x, y, 3);
    Border border(1, 2, 3);
    domino.setBorders(border, border, border, border);

    DominoGrid dg(7, 7);
    std::cout << "hello There" << std::endl;
    dg.setGrille();
    std::cout << "hello There2" << std::endl;
    dg.afficher();
    // Create a random domino from dg values

    std::cout << "-------------------" << std::endl;
    dg.afficher();
    // dg.setTuileOnGrid(4, 4, domino);
    dg.generateBorders();
    //dg.setDominoBorders();

    dg.setTuileOnGrid(4, 4, domino);
    dg.setTuileOnGrid(4, 3, domino);
    dg.generateNextDomino();
    test(dg);
}