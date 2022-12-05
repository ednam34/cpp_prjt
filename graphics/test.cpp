#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <array>
#include <tgmath.h>
#include "hpp/card.hpp"
#include "hpp/cardGrid.hpp"


const int WIDTH = 700;
const int HEIGHT = 500;


int main()
{
     //print hello world
     

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Card");

    // Create a card with numbers 3, 4, 5, and 6
    //Card card(4, 5, 6, 40,40);
    CardGrid grid(3, 3);

   

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
        
        window.draw(grid);
        //window.draw(text);
        window.display();

    }

    return 0;
}