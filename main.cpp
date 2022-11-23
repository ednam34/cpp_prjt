#include <SFML/Graphics.hpp>
#include <vector>
#include "hpp/tuile.hpp"
#include "hpp/grille.hpp"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>


int main()
{

        // Create the main window 
        sf::RenderWindow window(sf::VideoMode(500, 500), "SFML window");

        //create a vector of red tuiles 
        std::vector<Tuile> tuiles;
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                tuiles.push_back(Tuile(i*70+8,j*70+8,0));
            }
        }
        //create a grille with the vector of tuiles
        grille g(tuiles);

        // add the grille to the window
        

        //stay open until the user closes the window

        while (window.isOpen())
    {
        sf::Event event;

        if (event.type == sf::Event::MouseButtonPressed)
        {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        //check if the mouse is on a tuile of the grille
                        g.getTuile(event.mouseButton.x,event.mouseButton.y);

                }
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(g);
        window.display();
    }
    
}