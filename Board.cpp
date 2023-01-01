#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int TILE_SIZE = 50;
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 6;

// Enum to represent the state of a tile
enum class TileState { Empty, Player1, Player2 };
struct TilesDetails {
    sf::Texture texture;
    int BorderTop;
    int BorderBot;
    int BorderLeft;
    int BorderRight;
};
// Struct to represent a tile
struct Tile {
    int x;
    int y;
    TileState state;
    sf::Texture Tilecolor;
    int index;
    TilesDetails tileDetails;
};

// Class to represent the game board
class Board {
   public:
    TileState currentPlayer;
    // create a tab of 4 colors for the players
    std::array<sf::Texture, 7> textures;
    Tile tileNext;
    sf::Sprite colorSprite;
    // Create a struct of textures and 4 values

    // create a tab of 7 TilesDetails
    std::array<TilesDetails, 7> tilesDetails;

    Board() {
        tileNext = {-1, -1, TileState::Empty, textures[0], 1, tilesDetails[0]};

        textures[0].loadFromFile("textures/0.png");
        textures[1].loadFromFile("textures/1.png");
        textures[2].loadFromFile("textures/2.png");
        textures[3].loadFromFile("textures/3.png");
        textures[4].loadFromFile("textures/4.png");
        textures[5].loadFromFile("textures/5.png");
        textures[6].loadFromFile("textures/6.png");

        tilesDetails[0] = {textures[0], 0, 0, 0, 0};
        tilesDetails[1] = {textures[1], 1, 1, 2, 2};
        tilesDetails[2] = {textures[2], 2, 2, 1, 1};
        tilesDetails[3] = {textures[3], 1, 2, 1, 2};
        tilesDetails[4] = {textures[4], 1, 2, 2, 1};
        tilesDetails[5] = {textures[5], 2, 1, 2, 1};
        tilesDetails[6] = {textures[6], 2, 1, 1, 2};

        // Initialize all tiles to empty
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                tiles[y][x] = {x,           y, TileState::Empty,
                               textures[0], 0, tilesDetails[0]};
            }
        }

        // Seed the random number generator
        rng.seed(std::random_device{}());
    }

    void render(sf::RenderWindow& window) {
        // update colorSprite texture
        colorSprite.setTexture(textures[tileNext.index]);
        // Render all tiles
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                Tile tile = tiles[y][x];

                // Create a sprite for the tile
                sf::Sprite sprite;
                sprite.setPosition(tile.x * TILE_SIZE, tile.y * TILE_SIZE);

                // Set the texture of the sprite based on the state of the tile
                if (tile.state == TileState::Empty) {
                    // set the texture to white if the tile is empty
                    sprite.setTexture(textures[0]);
                } else {
                    sprite.setTexture(tile.Tilecolor);
                }

                window.draw(sprite);
            }
        }

        colorSprite.setPosition(BOARD_WIDTH * TILE_SIZE + 50, 50);
        if (currentPlayer == TileState::Player1) {
            // colorSprite.setTexture(textures[1]);
        } else {
            // colorSprite.setTexture(textures[1]);
        }
        window.draw(colorSprite);
    }
    bool isBoardEmpty() {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                if (tiles[y][x].state != TileState::Empty) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkAdjacentTile(int x, int y, Tile player) {
        if (isBoardEmpty()) {
            return true;
        }
        int adjacentTiles = 0;
        int NextTo = 0;
        // print the tile details
        // std::cout << "BorderTop: " << tiles[y][x - 1].tileDetails.BorderTop
        //<< std::endl;
        // std::cout << "BorderBot: " << tiles[y][x - 1].tileDetails.BorderBot
        //<< std::endl;
        std::cout << "BorderLeftACTUAL: " << tiles[y][x].tileDetails.BorderLeft
                  << std::endl;
        std::cout << "BorderLeft-1: " << tiles[y][x - 1].tileDetails.BorderLeft
                  << std::endl;
        std::cout << "BorderRight: " << tiles[y][x].tileDetails.BorderRight
                  << std::endl;
        std::cout << "BorderRight+1: "
                  << tiles[y][x + 1].tileDetails.BorderRight << std::endl;
        std::cout << "BorderTop: " << tiles[y][x].tileDetails.BorderTop
                  << std::endl;
        std::cout << "BorderTop+1: " << tiles[y - 1][x].tileDetails.BorderTop
                  << std::endl;
        std::cout << "BorderBot: " << tiles[y][x].tileDetails.BorderBot
                  << std::endl;
        std::cout << "BorderBot +1 : " << tiles[y + 1][x].tileDetails.BorderBot
                  << std::endl;

        // std::cout << "BorderRight: " << tiles[y][x -
        // 1].tileDetails.BorderRight
        //<< std::endl;
        // print x and yc
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        // print
        if ((x > 0 && tiles[y][x - 1].state != TileState::Empty &&
             tileNext.tileDetails.BorderLeft ==
                 tiles[y][x - 1].tileDetails.BorderRight) ||
            (x > 0 && tiles[y][x - 1].state == TileState::Empty) || (x == 0)) {
            if (tiles[y][x - 1].state != TileState::Empty && x != 0) {
                NextTo++;
            }
            // print premier argument passé
            std::cout << "1er OK" << std::endl;
            adjacentTiles++;
        }
        if ((x < BOARD_WIDTH - 1 && tiles[y][x + 1].state != TileState::Empty &&
             tileNext.tileDetails.BorderRight ==
                 tiles[y][x + 1].tileDetails.BorderLeft) ||
            (x < BOARD_WIDTH - 1 &&
             tiles[y][x + 1].state == TileState::Empty) ||
            (x == BOARD_WIDTH - 1)) {
            if (x != BOARD_WIDTH - 1 &&
                tiles[y][x + 1].state != TileState::Empty) {
                NextTo++;
            }
            // print deuxieme argument passé
            std::cout << "2eme OK" << std::endl;
            adjacentTiles++;
        }
        if ((y > 0 && tiles[y - 1][x].state != TileState::Empty &&
             tileNext.tileDetails.BorderTop ==
                 tiles[y - 1][x].tileDetails.BorderBot) ||
            (y > 0 && tiles[y - 1][x].state == TileState::Empty) || (y == 0)) {
            if (tiles[y - 1][x].state != TileState::Empty && y != 0) {
                NextTo++;
            }
            // print troisieme argument passé
            std::cout << "3eme OK" << std::endl;
            adjacentTiles++;
        }
        if ((y < BOARD_HEIGHT - 1 &&
             tiles[y + 1][x].state != TileState::Empty &&
             tileNext.tileDetails.BorderBot ==
                 tiles[y + 1][x].tileDetails.BorderTop) ||
            (y < BOARD_HEIGHT - 1 &&
             tiles[y + 1][x].state == TileState::Empty) ||
            (y == BOARD_HEIGHT - 1)) {
            if (y != BOARD_HEIGHT - 1 &&
                tiles[y + 1][x].state != TileState::Empty) {
                NextTo++;
            }
            // print quatrieme argument passé
            std::cout << "4eme OK" << std::endl;
            adjacentTiles++;
        }
        std::cout << "NexTO: " << NextTo << std::endl;
        if (adjacentTiles == 4 && NextTo > 0) {
            return true;
        } else {
            return false;
        }
    }
    // Place a tile on the board for the specified player
    bool placeTile(int x, int y, TileState player) {
        if (checkAdjacentTile(x, y, tiles[y][x]) == false) {
            std::cout << "Cannot place a tile on this tile." << std::endl;
            return false;
        }
        // Check if the tile is empty
        if (tiles[y][x].state == TileState::Empty) {
            // Place the tile
            tiles[y][x].state = player;
            // Get the texture of colorSprite and put it in the tile
            tiles[y][x].tileDetails = tileNext.tileDetails;
            tiles[y][x].Tilecolor = tileNext.Tilecolor;
            colorSprite.setTexture(tiles[y][x].Tilecolor);
            tileNext.Tilecolor = textures[1];
            colorSprite.setTexture(tileNext.Tilecolor);
            tiles[y][x].tileDetails.BorderTop = tileNext.tileDetails.BorderTop;
            tiles[y][x].tileDetails.BorderBot = tileNext.tileDetails.BorderBot;
            tiles[y][x].tileDetails.BorderLeft =
                tileNext.tileDetails.BorderLeft;
            tiles[y][x].tileDetails.BorderRight =
                tileNext.tileDetails.BorderRight;
            tileNext.tileDetails.BorderTop = tilesDetails[1].BorderTop;
            tileNext.tileDetails.BorderBot = tilesDetails[1].BorderBot;
            tileNext.tileDetails.BorderLeft = tilesDetails[1].BorderLeft;
            tileNext.tileDetails.BorderRight = tilesDetails[1].BorderRight;
            tileNext.tileDetails.texture = textures[1];
            tileNext.index = 1;
            return true;

        } else {
            // Tile is not empty, do not place the tile
            std::cout << "Cannot place a tile on a non-empty tile."
                      << std::endl;
            return false;
        }
    }

    void rotateTile() {
        // Get a random texture index
        int indexN = tileNext.index + 1;
        if (indexN > 6) {
            indexN = 1;
        }
        tileNext.index = indexN;
        colorSprite.setTexture(tilesDetails[indexN].texture);
        tileNext.Tilecolor = tilesDetails[indexN].texture;
        tileNext.tileDetails = tilesDetails[indexN];
    }

   private:
    Tile tiles[6][8];
    std::mt19937 rng;

    sf::Texture generateRandomTexture() {
        // take a random number between 0 and 3 and return the texture at that
        // index
        std::uniform_int_distribution<int> dist(1, 4);
        return textures[dist(rng)];
    }

    int generateRandomTextureIndex() {
        // take a random number between 0 and 3 and return the index
        std::uniform_int_distribution<int> dist(1, 4);
        return dist(rng);
    }
};

int main() {
    // Create the window and the game board
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "Tile Game");
    Board board;

    // Initialize the current player to player 1
    TileState currentPlayer = TileState::Player1;

    // Run the game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // check if the click is a left click
                if (event.mouseButton.button != sf::Mouse::Left) {
                    board.rotateTile();
                    // print a message if the click is not a left click
                    /*std::cout << "Please use the left mouse button."
                              << std::endl;*/
                } else {
                    // Handle a mouse click event
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;
                    bool a = board.placeTile(x, y, currentPlayer);

                    // Switch to the other player's turn
                    if (a && currentPlayer == TileState::Player1) {
                        currentPlayer = TileState::Player2;
                        board.currentPlayer = TileState::Player2;
                        // print player 2 turn
                        std::cout << "Player 2 turn" << std::endl;
                    } else if (a && currentPlayer == TileState::Player2) {
                        currentPlayer = TileState::Player1;
                        board.currentPlayer = TileState::Player1;
                        std::cout << "Player 1 turn" << std::endl;
                    }
                }
            }
        }
        window.clear();
        board.render(window);
        window.display();
    }

    return 0;
}
