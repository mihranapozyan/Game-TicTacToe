#include "Game.h"
#include <iostream>

#include "AIPlayer.h"
#include "HumanPlayer.h"

// Constructor that initializes the game with a human player for X and AI for O
// Initially, player X (Human) starts the game.
Game::Game() {
    m_playerX = std::make_unique<HumanPlayer>(CellState::X);  // Create player X (Human)
    m_playerO = std::make_unique<AIPlayer>(CellState::O);      // Create player O (AI)

    m_currentPlayer = std::move(m_playerX);  // Player X goes first
}

// Prints the welcome header for the game
void Game::printHeader() const {
    std::cout << "Welcome to the game of TicTacToe!\n";  // Display game header
}

// Starts the game and manages the game loop
// It alternates between players until a winner is found or the game is drawn.
void Game::play() {
    printHeader();  // Display the game header

    while (true) {
        m_board.printBoard();                        // Print the current state of the board
        m_board.printAvailableMoves();               // Print available moves for the current player

        std::cout << "Player " << m_currentPlayer->getSymbol() << " enter your move:" << std::endl;

        // Let the current player make a move, if it's invalid, prompt again
        if (!m_currentPlayer->makeMove(m_board)) {
            std::cerr << "Invalid input. Please try again." << std::endl;
            continue;  // Continue loop if the move was invalid
        }

        // Check if the current player has won the game
        if (m_board.checkWin(m_currentPlayer->getSymbol())) {
            m_board.printBoard();  // Print the final board state
            std::cout << "Player " << (m_currentPlayer->getSymbol() == CellState::X ? "X" : "O") << " wins!\n";
            break;  // End game if there's a winner
        }

        // Check if the game is a draw (no more valid moves and no winner)
        if (m_board.checkDraw()) {
            m_board.printBoard();  // Print the final board state
            std::cout << "The game is a draw!\n";
            break;  // End game if it's a draw
        }

        // Switch to the next player (X <-> O)
        m_currentPlayer = switchPlayer();  // Alternate between players
    }
}

// Switches the current player based on the symbol (X or O)
// If the current player is X, it switches to O, and vice versa.
std::unique_ptr<Player> Game::switchPlayer() const {
    if (m_currentPlayer->getSymbol() == CellState::X) {
        return std::make_unique<AIPlayer>(CellState::O);  // Switch to player O (AI)
    } else {
        return std::make_unique<HumanPlayer>(CellState::X);  // Switch to player X (Human)
    }
}
