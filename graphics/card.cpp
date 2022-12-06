#include "hpp/card.hpp"

//const int CARD_SIZE = 65;

Card::Card(){
    font.loadFromFile("arial.ttf");

    numbersN[0] = 1;
    numbersN[1] = 2;
    numbersN[2] = 3;

    numbersS[0] =  1;
    numbersS[1] =  2;
    numbersS[2] =  3;

    numbersE[0] = 1;
    numbersE[1] = 2;
    numbersE[2] =  3;

    numbersW[0] = 1;
    numbersW[1] = 2;
    numbersW[2] = 3;

    // Create the rectangle shape
    rect.setSize(sf::Vector2f(CARD_SIZE, CARD_SIZE));
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(2);
    rect.setOutlineColor(sf::Color::Black);
    rect.setPosition(50, 50);

    // Create the text objects for the numbers
    for (int i = 0; i < 3; i++)
    {
        textN[i].setFont(font);
        textN[i].setString(std::to_string(numbersN[i]));
        textN[i].setCharacterSize(10);
        textN[i].setFillColor(sf::Color::Black);
        textN[i].setPosition(50, 50);

        textS[i].setFont(font);
        textS[i].setString(std::to_string(numbersS[i]));
        textS[i].setCharacterSize(10);
        textS[i].setFillColor(sf::Color::Black);
        textS[i].setPosition(50, 50);

        textE[i].setFont(font);
        textE[i].setString(std::to_string(numbersE[i]));
        textE[i].setCharacterSize(10);
        textE[i].setFillColor(sf::Color::Black);
        textE[i].setPosition(50, 50);

        textW[i].setFont(font);
        textW[i].setString(std::to_string(numbersW[i]));
        textW[i].setCharacterSize(10);
        textW[i].setFillColor(sf::Color::Black);
        textW[i].setPosition(50, 50);
    }
}

Card::Card(int top, int right, int bottom, int x, int y)
    {
        font.loadFromFile("arial.ttf");

        /*numbers[0] = top;
        numbers[1] = right;
        numbers[2] = bottom;
        numbers[3] = left;*/

        numbersN[0] = top;
        numbersN[1] = right;
        numbersN[2] = bottom;

        numbersS[0] =  top;
        numbersS[1] =  right;
        numbersS[2] =  bottom;

        numbersE[0] = top;
        numbersE[1] = right;
        numbersE[2] =  bottom;

        numbersW[0] = top;
        numbersW[1] = right;
        numbersW[2] = bottom;

        // Create the rectangle shape
        rect.setSize(sf::Vector2f(CARD_SIZE, CARD_SIZE));
        rect.setFillColor(sf::Color::White);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color::Black);
        rect.setPosition(x, y);

        // Create the text objects for the numbers
        for (int i = 0; i < 3; i++)
        {
            /*texts[i].setFont(font);
            texts[i].setString(std::to_string(numbers[i]));
            texts[i].setCharacterSize(20);
            texts[i].setFillColor(sf::Color::Black);*/
            textN[i].setFont(font);
            textN[i].setString(std::to_string(numbersN[i]));
            textN[i].setCharacterSize(10);
            textN[i].setFillColor(sf::Color::Black);

            textS[i].setFont(font);
            textS[i].setString(std::to_string(numbersS[i]));
            textS[i].setCharacterSize(10);
            textS[i].setFillColor(sf::Color::Black);

            textE[i].setFont(font);
            textE[i].setString(std::to_string(numbersE[i]));
            textE[i].setCharacterSize(10);
            textE[i].setFillColor(sf::Color::Black);

            textW[i].setFont(font);
            textW[i].setString(std::to_string(numbersW[i]));
            textW[i].setCharacterSize(10);
            textW[i].setFillColor(sf::Color::Black);

        }

        // Set the position of the numbers on the card
        /*texts[0].setPosition(CARD_SIZE / 2 - texts[0].getGlobalBounds().width / 2, 10);
        texts[1].setPosition(CARD_SIZE - texts[1].getGlobalBounds().width - 10, CARD_SIZE / 2 - texts[1].getGlobalBounds().height / 2);
        texts[2].setPosition(CARD_SIZE / 2 - texts[2].getGlobalBounds().width / 2, CARD_SIZE - texts[2].getGlobalBounds().height - 10);
        texts[3].setPosition(10, CARD_SIZE / 2 - texts[3].getGlobalBounds().height / 2);*/

        textN[0].setPosition((CARD_SIZE / 1.5 - textN[0].getGlobalBounds().width / 1.5)+x, 10+y);
        textN[1].setPosition((CARD_SIZE / 2 -   textN[1].getGlobalBounds().width / 2)+x, 10+y);
        textN[2].setPosition((CARD_SIZE / 3 -   textN[2].getGlobalBounds().width / 3)+x, 10+y);

        textS[0].setPosition((CARD_SIZE - textS[0].getGlobalBounds().width - 10)+x, (CARD_SIZE / 1.5 - textS[0].getGlobalBounds().height / 1.5)+y);
        textS[1].setPosition((CARD_SIZE - textS[1].getGlobalBounds().width - 10)+x, (CARD_SIZE / 2 - textS[1].getGlobalBounds().height / 2)+y);
        textS[2].setPosition((CARD_SIZE - textS[2].getGlobalBounds().width - 10)+x, (CARD_SIZE / 3 - textS[2].getGlobalBounds().height / 3)+y);

        textE[0].setPosition((CARD_SIZE / 1.5 - textE[0].getGlobalBounds().width / 1.5)+x, (CARD_SIZE - textE[0].getGlobalBounds().height - 10)+y);
        textE[1].setPosition((CARD_SIZE / 2 - textE[1].getGlobalBounds().width / 2)+x, (CARD_SIZE - textE[1].getGlobalBounds().height - 10)+y);
        textE[2].setPosition((CARD_SIZE / 3 - textE[2].getGlobalBounds().width / 3)+x, (CARD_SIZE - textE[2].getGlobalBounds().height - 10)+y);


        textW[0].setPosition(10+x, (CARD_SIZE / 1.5 - textW[0].getGlobalBounds().height / 1.5)+y);
        textW[1].setPosition(10+x, (CARD_SIZE / 2 - textW[1].getGlobalBounds().height / 2)+y);
        textW[2].setPosition(10+x, (CARD_SIZE / 3 - textW[2].getGlobalBounds().height / 3)+y);

    }

Card::Card(Domino domino, int x, int y){
        font.loadFromFile("arial.ttf");

        /*numbers[0] = top;
        numbers[1] = right;
        numbers[2] = bottom;
        numbers[3] = left;*/

        numbersN[0] = domino.getN().getA();
        numbersN[1] = domino.getN().getB();
        numbersN[2] =  domino.getN().getC();

        numbersS[0] =  domino.getS().getA();
        numbersS[1] =  domino.getS().getB();
        numbersS[2] =  domino.getS().getC();

        numbersE[0] = domino.getE().getA();
        numbersE[1] = domino.getE().getB();
        numbersE[2] = domino.getE().getC();

        numbersW[0] = domino.getW().getA();
        numbersW[1] = domino.getW().getB();
        numbersW[2] = domino.getW().getC();

        // Create the rectangle shape
        rect.setSize(sf::Vector2f(CARD_SIZE, CARD_SIZE));
        rect.setFillColor(sf::Color::White);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color::Black);
        rect.setPosition(x, y);

        // Create the text objects for the numbers
        for (int i = 0; i < 3; i++)
        {
            /*texts[i].setFont(font);
            texts[i].setString(std::to_string(numbers[i]));
            texts[i].setCharacterSize(20);
            texts[i].setFillColor(sf::Color::Black);*/
            textN[i].setFont(font);
            textN[i].setString(std::to_string(numbersN[i]));
            textN[i].setCharacterSize(10);
            textN[i].setFillColor(sf::Color::Black);

            textS[i].setFont(font);
            textS[i].setString(std::to_string(numbersS[i]));
            textS[i].setCharacterSize(10);
            textS[i].setFillColor(sf::Color::Black);

            textE[i].setFont(font);
            textE[i].setString(std::to_string(numbersE[i]));
            textE[i].setCharacterSize(10);
            textE[i].setFillColor(sf::Color::Black);

            textW[i].setFont(font);
            textW[i].setString(std::to_string(numbersW[i]));
            textW[i].setCharacterSize(10);
            textW[i].setFillColor(sf::Color::Black);

        }

        // Set the position of the numbers on the card

        textN[2].setPosition((CARD_SIZE / 1.5 - textN[2].getGlobalBounds().width / 1.5)+x, 10+y);
        textN[1].setPosition((CARD_SIZE / 2 -   textN[1].getGlobalBounds().width / 2)+x, 10+y);
        textN[0].setPosition((CARD_SIZE / 3 -   textN[0].getGlobalBounds().width / 3)+x, 10+y);

        textS[2].setPosition((CARD_SIZE - textS[2].getGlobalBounds().width - 10)+x, (CARD_SIZE / 1.5 - textS[2].getGlobalBounds().height / 1.5)+y);
        textS[1].setPosition((CARD_SIZE - textS[1].getGlobalBounds().width - 10)+x, (CARD_SIZE / 2 - textS[1].getGlobalBounds().height / 2)+y);
        textS[0].setPosition((CARD_SIZE - textS[0].getGlobalBounds().width - 10)+x, (CARD_SIZE / 3 - textS[0].getGlobalBounds().height / 3)+y);

        textE[2].setPosition((CARD_SIZE / 1.5 - textE[2].getGlobalBounds().width / 1.5)+x, (CARD_SIZE - textE[2].getGlobalBounds().height - 10)+y);
        textE[1].setPosition((CARD_SIZE / 2 - textE[1].getGlobalBounds().width / 2)+x, (CARD_SIZE - textE[1].getGlobalBounds().height - 10)+y);
        textE[0].setPosition((CARD_SIZE / 3 - textE[0].getGlobalBounds().width / 3)+x, (CARD_SIZE - textE[0].getGlobalBounds().height - 10)+y);


        textW[2].setPosition(10+x, (CARD_SIZE / 1.5 - textW[2].getGlobalBounds().height / 1.5)+y);
        textW[1].setPosition(10+x, (CARD_SIZE / 2 - textW[1].getGlobalBounds().height / 2)+y);
        textW[0].setPosition(10+x, (CARD_SIZE / 3 - textW[0].getGlobalBounds().height / 3)+y);

    }

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rect);
        for (int i = 0; i < 3; i++)
        {
            //std::cout << "Hello World!" << std::endl;   

            target.draw(textN[i]);
            target.draw(textS[i]);
            target.draw(textE[i]);
            target.draw(textW[i]);
        }
    }