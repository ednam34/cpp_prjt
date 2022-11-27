// create grille.hpp

#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "tuile.hpp"
#include "domino.hpp"

class grille : public sf::Drawable
{
    public:
        grille();
        grille(std::vector<Tuile> tuiles);
        virtual ~grille();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setType(int type);
        Tuile getTuile(int x, int y);
    private:
        std::vector<Tuile> tuiles;
};




#endif