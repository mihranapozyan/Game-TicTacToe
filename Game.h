#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Board.h"
#include "Player.h"

// Class representing the game logic for Tic-Tac-Toe
// Manages the game board, players, and handles the game flow.
class Game {

    Board m_board;                            // The game board, containing the cells for X, O, or EMPTY
    std::unique_ptr<Player> m_currentPlayer;  // The current player (either X or O)
    std::unique_ptr<Player> m_playerO;        // Player O (initially AI)
    std::unique_ptr<Player> m_playerX;        // Player X (initially Human)

public:
    // Constructor to initialize the game with two players
    // Sets up Player X as a Human and Player O as AI.
    Game();

    // Method to start and run the game loop
    // The loop continues until there's a winner or a draw.
    void play();

    // Method to switch between players (X -> O, O -> X)
    // Returns the new player based on the current one.
    [[nodiscard]] std::unique_ptr<Player> switchPlayer() const;

private:
    // Method to print the game header and welcome message
    // This is shown at the start of the game.
    void printHeader() const;
};

#endif // GAME_H
