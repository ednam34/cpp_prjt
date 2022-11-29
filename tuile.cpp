//incule tuile.hpp

#include "hpp/tuile.hpp"


Tuile::Tuile()
{
    //ctor
}

Tuile::Tuile(int x, int y, int type)
{
    this->x = x;
    this->y = y;
    this->type = type;
    rect.setSize(sf::Vector2f(65,65));
    rect.setPosition(x,y);
    rect.setFillColor(sf::Color::Red);
}

Tuile::~Tuile()
{
    //dtor
}

void Tuile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect);
   
}

void Tuile::drawText(sf::RenderTarget& target, sf::RenderStates states,int a) const
{
    //add text to the tuile
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/arial.ttf");
    text.setFont(font);
    text.setString(std::to_string(a));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x,y);
    target.draw(text);
    
}

void Tuile::setX(int x)
{
    this->x = x;
}

void Tuile::setY(int y)
{
    this->y = y;
}

int Tuile::getX()
{
    return x;
}
int Tuile::getY()
{
    return y;
}

void Tuile::changeColor()
{
    if(this->type == 0)
    {
        rect.setFillColor(sf::Color::Blue);
        this->type = 1;
    }
    else
    {
        rect.setFillColor(sf::Color::Red);
        this->type = 0;
    }
}

int Tuile::getType()
{
    return type;
}

void Tuile::setType(int type)
{
    this->type = type;
}

sf::RectangleShape Tuile::getRect()
{
    return rect;
}



