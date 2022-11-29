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
        grille(std::vector<Tuile> tuiles, int gameType);
        grille(std::vector<Domino> dominos, int gameType);
        virtual ~grille();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setType(int type);
        void setTuiles(std::vector<Domino> tuiles);
        Tuile getTuile(int x, int y);
    private:
        std::vector<Tuile> tuiles;
        std::vector<Domino> dominos;
        int gameType;
};




#endif