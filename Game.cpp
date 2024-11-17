
#include "Game.h"
#include <iostream>
#include "AIPlayer.h"
#include "HumanPlayer.h"

// Constructor that initializes the game with a specified game mode.
Game::Game(const GameMode am_mode) : m_gameMode(am_mode) {
    // If the game mode is HumanVsAI, Player X is Human and Player O is AI.
    if (am_mode == GameMode::HumanVsAI) {
        m_playerX = std::make_unique<HumanPlayer>(CellState::X);  // Player X (Human)
        m_playerO = std::make_unique<AIPlayer>(CellState::O);     // Player O (AI)
    }
    // If the game mode is HumanVsHuman, both Player X and Player O are Human.
    else {
        m_playerX = std::make_unique<HumanPlayer>(CellState::X);  // Player X (Human)
        m_playerO = std::make_unique<HumanPlayer>(CellState::O);  // Player O (Human)
    }
    
    // Set Player X to start the game.
    m_currentPlayer = std::move(m_playerX);
}

// Prints the welcome header for the game
void Game::printHeader() const {
    std::cout << "Welcome to the game of TicTacToe!\n";  // Display game header
}

// Starts the game and manages the game loop
void Game::play() {
    printHeader();  // Display the game header

    // Main game loop that continues until there's a winner or a draw
    while (true) {
        m_board.printBoard();                        // Print the current state of the board
        m_board.printAvailableMoves();               // Print available moves for the current player

        std::cout << "Player " << m_currentPlayer->getSymbol() << " enter your move:" << std::endl;

        // Let the current player make a move. If the move is invalid, prompt again.
        if (!m_currentPlayer->makeMove(m_board)) {
            std::cerr << "Invalid input. Please try again." << std::endl;
            continue;  // Continue loop if the move was invalid
        }

        // Check if the current player has won the game.
        if (m_board.checkWin(m_currentPlayer->getSymbol())) {
            m_board.printBoard();  // Print the final board state
            std::cout << "Player " << (m_currentPlayer->getSymbol() == CellState::X ? "X" : "O") << " wins!\n";
            break;  // End the game if there's a winner
        }

        // Check if the game is a draw (no more valid moves and no winner).
        if (m_board.checkDraw()) {
            m_board.printBoard();  // Print the final board state
            std::cout << "The game is a draw!\n";
            break;  // End the game if it's a draw
        }

        // Switch to the next player (X <-> O)
        m_currentPlayer = switchPlayer(m_gameMode);
    }
}

// Switches the current player based on the symbol (X -> O, O -> X)
// Takes into account the game mode (HumanVsHuman or HumanVsAI).
std::unique_ptr<Player> Game::switchPlayer(const GameMode am_mode) const {
    // In HumanVsAI mode, switch between Human (X) and AI (O) players.
    if (m_gameMode == GameMode::HumanVsAI) {
        if (m_currentPlayer->getSymbol() == CellState::X) {
            return std::make_unique<AIPlayer>(CellState::O);  // Switch to player O (AI)
        } else {
            return std::make_unique<HumanPlayer>(CellState::X);  // Switch to player X (Human)
        }
    }

    // In HumanVsHuman mode, switch between two Human players.
    if (m_currentPlayer->getSymbol() == CellState::X) {
        return std::make_unique<HumanPlayer>(CellState::O);  // Switch to player O (Human)
    } else {
        return std::make_unique<HumanPlayer>(CellState::X);  // Switch to player X (Human)
    }
}