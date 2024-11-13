#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "CellState.h"

class Board {
public:
    static constexpr int SIZE = 9;  // Total number of cells on the board (3x3 grid)

private:
    std::array<CellState, SIZE> m_board{};  // Array representing the board, each cell can be X, O, or EMPTY

public:
    // Constructors and destructors
    Board();             // Constructor to initialize the board
    ~Board() = default;  // Default destructor

    // Functions
    void printBoard() const;                                                // Method to print the current state of the board
    void printAvailableMoves() const;                                       // Method to print the available moves
    void makeMove(CellState ac_player, int ai_move);                        // Method to place a player's move on the board
    [[nodiscard]] bool checkWin(CellState ac_player) const;                 // Method to check if a player has won
    [[nodiscard]] bool checkDraw() const;                                   // Method to check if the game is a draw
    [[nodiscard]] bool checkMove(int ai_move) const;                        // Method to check if a move is valid
    [[nodiscard]] CellState getSymbol(int ai_row, int a_col) const;         // Get the symbol at a specific board position
};

#endif // BOARD_H
