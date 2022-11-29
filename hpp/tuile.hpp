//create tuile.hpp

#ifndef TUILE_HPP
#define TUILE_HPP
#include <SFML/Graphics.hpp>


class Tuile : public sf::Drawable
{
    //tuile est un carré de 50*50

    public:
        Tuile();
        Tuile(int x, int y, int type);
        virtual ~Tuile();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void drawText(sf::RenderTarget& target, sf::RenderStates states, int a) const;
        void changeColor();
        void setX(int x);
        void setY(int y);
        void setType(int t);
        int getX();
        int getY();
        int getType();
        sf::RectangleShape getRect();
        
    protected:
        int x;
        int y;
        int type;
        sf::RectangleShape rect;    
};
#endif 