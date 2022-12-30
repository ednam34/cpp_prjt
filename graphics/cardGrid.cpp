#include "hpp/cardGrid.hpp"

#include <tgmath.h>

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

#include "hpp/card.hpp"

CardGrid::CardGrid() {
    /*for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cards.push_back(Card(1, 2, 3, 50, 50));
        }
    }*/
    cards.push_back(Card(1, 2, 3, 50, 50));
    // card = Card(1, 2, 3, 50, 50);
}

CardGrid::CardGrid(int rows, int cols, DominoGrid& dominoGrid) {
    //put all the cards in the vector
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cards.push_back(Card(dominoGrid.getTuile(i, j), 72 * i, 72 * j));
        }
    }
    cardTest = Card(1, 2, 3, 50, 50);
    this->dominoGrid = dominoGrid;
    this->dominoGrid.afficher();
}

Card CardGrid::getCard(int i) { return this->cardTest; }

DominoGrid CardGrid::getDominoGrid() { return this->dominoGrid; }

void CardGrid::setCard(int i, int j, int x, int y) {
    Domino domino = dominoGrid.getTuile(i, j);
    cards[i] = Card(domino, x, y);
}

void CardGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // print hello world
    // target.draw(cards[0]);
    // std::cout << "Hello World!" << std::endl;
    Border border(1, 2, 5);
    Border border2(4, 7, 5);
    Border border3(1, 2, 2);
    Border border4(6, 2, 8);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // Domino domino = dominoGrid.getTuiles()[i][j];
            // domino.setBorders(border, border2, border3, border4);
            // Card(domino, 72*j, 72*i).draw(target, states);
            /*this->setCard(i, j, 72*j, 72*i);
            Card(getDominoGrid().getTuiles()[i][j], 72*j, 72*i).draw(target,
            states); target.draw(Card(dominoGrid.getTuiles()[i][j], 72*j,
            72*i)); */
        }
    }
}

void CardGrid::myDraw(sf::RenderTarget& target, sf::RenderStates states) {

    for (int i = 0; i < cards.size()-8; i++) {
        //pritn i
        //std::cout << "i " << i << std::endl;
        cards[i].getDomino().printBorders();
        target.draw(cards[i]);
    }
}

void CardGrid::UpdateNextCard(sf::RenderTarget& target,
                              sf::RenderStates states) {
    // Draw top right corner of the window a white circle
    target.draw(Card(dominoGrid.getNextDomino(), 600, 30));
    // write under the domino "Player One"
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Player One");
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setPosition(600, 0);
    target.draw(text);
}

void CardGrid::changeDominoColor(int x, int y) {
    Domino domino = dominoGrid.getTuileXY(x, y);
    //get the card at the position x, y
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            
        }
    }
}