#include <SFML/Graphics.hpp>
#include <vector>
#include "hpp/tuile.hpp"
#include "hpp/grille.hpp"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "hpp/domino.hpp"


int main()
{

        // Create the main window with white background

        sf::RenderWindow window(sf::VideoMode(700, 500), "SFML window");
        window.setFramerateLimit(60);


        //create a vector of tuiles 
        std::vector<Tuile> tuiles;
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                tuiles.push_back(Tuile(i*70+8,j*70+8,0));
            }
        }

        //create a vector of domino
        std::vector<Tuile> dominos;
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                dominos.push_back(Domino(i*70+8,j*70+8,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}));
            }
        }


        //create a grille with the vector of tuiles
        grille g(dominos);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

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
        }

        window.clear();
        window.draw(g);
        window.display();
    }
    
}