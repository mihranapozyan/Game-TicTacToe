#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Board.h"
#include "Player.h"

// Enum to define different game modes
enum class GameMode {
    HumanVsAI,  // Human vs AI mode
    HumanVsHuman  // Human vs Human mode
};

// Class representing the game logic for Tic-Tac-Toe
// Manages the game board, players, and handles the game flow.
class Game {

    Board m_board;                            // The game board, containing the cells for X, O, or EMPTY
    std::unique_ptr<Player> m_currentPlayer;  // The current player (either X or O)
    std::unique_ptr<Player> m_playerO;        // Player O (initially AI)
    std::unique_ptr<Player> m_playerX;        // Player X (initially Human)
    GameMode m_gameMode;                     // The selected game mode (HumanVsHuman or HumanVsAI)

public:
    // Constructor to initialize the game with the selected game mode.
    // Sets up Player X as Human and Player O as AI if GameMode is HumanVsAI,
    // or both as Human if GameMode is HumanVsHuman.
    Game(GameMode);

    // Method to start and run the game loop.
    // The loop continues until there's a winner or a draw.
    void play();

    // Method to switch between players (X -> O, O -> X) based on the current player and game mode.
    // This handles alternating between human players and switching to AI where applicable.
    [[nodiscard]] std::unique_ptr<Player> switchPlayer(GameMode am_mode) const;

private:
    // Method to print the game header and welcome message.
    // This is shown at the start of the game.
    void printHeader() const;
};

#endif // GAME_H