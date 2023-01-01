#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <random>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int TILE_SIZE = 50;
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 6;

// Enum to represent the state of a tile
enum class TileState { Empty, Player1, Player2 };

// Struct to represent a tile
struct Tile {
    int x;
    int y;
    TileState state;
    int Tilecolor;
    int value;
};

// Class to represent the game board
class Board {
   public:
    TileState currentPlayer;
    // create an array of textures for the players
    std::array<sf::Texture, 4> textures;

    Board();
    void render(sf::RenderWindow& window);
    bool placeTile(int x, int y, TileState player);
    bool isBoardEmpty();

   private:
    Tile tiles[6][8];
    std::mt19937 rng;
    sf::Texture generateRandomTexture();
    int generateRandomTextureIndex();
    void rotateTile();
};

#endif  // BOARD_HPP