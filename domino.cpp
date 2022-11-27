//domino 

//domino.cpp
#include "hpp/domino.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Domino::Domino()
{
    //ctor
}

Domino::Domino(int x, int y, int type, std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d)
{
    this->x = x;
    this->y = y;
    this->type = type;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    rect.setSize(sf::Vector2f(65,65));
    rect.setPosition(x,y);
    rect.setFillColor(sf::Color::Red);
}

Domino::~Domino()
{
    //dtor
}

void Domino::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect);
    //draw the vector a on the left side
    for(int i = 0; i < a.size(); i++)
    {
        sf::Text text;
        sf::Font font;
        font.loadFromFile("font/arial.ttf");
        text.setFont(font);
        text.setString(std::to_string(a[i]));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(x,y);
        target.draw(text);
    }

}