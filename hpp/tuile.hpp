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
        void changeColor();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        int getType();
        void setType(int t);
    private:
        int x;
        int y;
        int type;
        sf::RectangleShape rect;    
};
#endif 