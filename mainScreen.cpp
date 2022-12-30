#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 500;

// Enum to represent the different menu options
enum MenuOption {
    DOMINO,
    TRAX,
    CARCASSONNE
};

int mainMenuFunc(sf::RenderWindow& window)
{

    // Set up the font and text for the menu options
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }

    sf::Text dominoText("Domino", font, 24);
    sf::Text traxText("Trax", font, 24);
    sf::Text carcassonneText("Carcassonne", font, 24);

    // Set the position of the text
    dominoText.setPosition(sf::Vector2f(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 - 50));
    traxText.setPosition(sf::Vector2f(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2));
    carcassonneText.setPosition(sf::Vector2f(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 + 50));

    // Set up the initial selected menu option
    MenuOption selectedOption = DOMINO;
    dominoText.setFillColor(sf::Color::Red);

    // Run the game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                // Check if the up or down arrow keys were pressed
                if (event.key.code == sf::Keyboard::Up) {
                    // Change the selected option
                    switch (selectedOption) {
                        case DOMINO:
                            selectedOption = CARCASSONNE;
                            break;
                        case TRAX:
                            selectedOption = DOMINO;
                            break;
                        case CARCASSONNE:
                            selectedOption = TRAX;
                            break;
                    }
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    // Change the selected option
                    switch (selectedOption) {
                        case DOMINO:
                            selectedOption = TRAX;
                            break;
                        case TRAX:
                            selectedOption = CARCASSONNE;
                            break;
                        case CARCASSONNE:
                            selectedOption = DOMINO;
                            break;
                    }
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    // The user has selected a menu option
                    switch (selectedOption) {
                        case DOMINO:
                            return 3;
                            break;
                        case TRAX:
                            // Start the trax game
                            break;
                        case CARCASSONNE:
                            // Start the carcassonne game
                            break;
                    }
                }
            }
            // Update the selected menu option
            dominoText.setFillColor(sf::Color::White);
            traxText.setFillColor(sf::Color::White);
            carcassonneText.setFillColor(sf::Color::White);
            switch (selectedOption) {
                case DOMINO:
                    dominoText.setFillColor(sf::Color::Red);
                    break;
                case TRAX:
                    traxText.setFillColor(sf::Color::Red);
                    break;
                case CARCASSONNE:
                    carcassonneText.setFillColor(sf::Color::Red);
                    break;
            }
            //draw the menu
            window.clear();
            window.draw(dominoText);
            window.draw(traxText);
            window.draw(carcassonneText);
            window.display();
            
        }
    }
    return 0;
}

