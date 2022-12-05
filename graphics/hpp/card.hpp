#ifndef CARD_HPP
#define CARD_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <array>

class Card : public sf::Drawable
{
public:
    // Constructor
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Card();
    Card(int top, int right, int bottom, int x, int y);
    //~Card();
    int CARD_SIZE = 65;
protected:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
    std::array<int, 3> numbersN;
    std::array<int, 3> numbersS;
    std::array<int, 3> numbersE;
    std::array<int, 3> numbersW;
    std::array<sf::Text, 3> textN;
    std::array<sf::Text, 3> textS;
    std::array<sf::Text, 3> textE;
    std::array<sf::Text, 3> textW;

};


#endif