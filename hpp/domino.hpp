//domino is a tuile with 3x3 numbers on sides
// Compare this snippet from hpp/domino.hpp:
#ifndef DOMINO_HPP
#define DOMINO_HPP
#include "tuile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Domino : public Tuile
{
    public:
        Domino();
        Domino(int x, int y, int type, std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d);
        virtual ~Domino();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private: 
        std::vector<int> a;
        std::vector<int> b;
        std::vector<int> c;
        std::vector<int> d;
        int x;
        int y;
        int type;
        sf::RectangleShape rect;
};

#endif