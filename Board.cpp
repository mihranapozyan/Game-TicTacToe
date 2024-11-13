#include "Board.h"
#include <algorithm>
#include <iostream>

// Constructor that initializes the board with all cells set to EMPTY
Board::Board() {
    m_board.fill(CellState::EMPTY);         // Initialize the board with all cells set to EMPTY
}

/**
 * Prints the current state of the board.
 * The board is printed in a 3x3 grid, with each cell showing either a number (if empty),
 * 'X' (if occupied by player X), or 'O' (if occupied by player O).
 */
void Board::printBoard() const {
    for (int i = 0; i < SIZE; i++) {
        if (m_board[i] == CellState::EMPTY) {
            std::cout << " " << (i + 1) << " ";  // Print the number if the cell is empty (for user input)
        } else if (m_board[i] == CellState::X) {
            std::cout << " X ";                  // Print X if the cell is occupied by player X
        } else if (m_board[i] == CellState::O) {
            std::cout << " O ";                  // Print O if the cell is occupied by player O
        }

        // Print the separator between cells, unless it's the last cell in a row
        if ((i + 1) % 3 != 0) {
            std::cout << "|";                   // Vertical separator between cells
        } else {
            std::cout << std::endl;             // Newline at the end of each row
            if (i != 8) {
                std::cout << "---+---+---\n";   // Separator between rows (not after the last row)
            }
        }
    }
}

/**
 * Prints all available (empty) cells on the board with their corresponding cell numbers.
 * This helps the player know where they can make a move.
 */
void Board::printAvailableMoves() const {
    std::cout << "Available moves: ";
    for (int i = 0; i < SIZE; ++i) {
        // Print the number of the cell if it is empty (i.e., a valid move)
        if (m_board[i] == CellState::EMPTY) {
            std::cout << "(" << (i + 1) << ") ";  // Print the move number (i + 1 to match human-readable indexing)
        }
    }
    std::cout << "\n";
}

/**
 * Checks if a player has won the game.
 * A player wins if they have three of their marks (X or O) in a row, column, or diagonal.
 *
 * @param ac_player The player to check (either X or O)
 * @return true if the player has won, false otherwise
 */
bool Board::checkWin(const CellState ac_player) const {
    // Define all possible win patterns (rows, columns, and diagonals)
    static constexpr int winPatterns[8][3] = {
        {0, 1, 2},      // Top row
        {3, 4, 5},      // Middle row
        {6, 7, 8},      // Bottom row
        {0, 4, 8},      // Main diagonal
        {6, 4, 2},      // Anti-diagonal
        {0, 3, 6},      // Left column
        {1, 4, 7},      // Middle column
        {2, 5, 8}       // Right column
    };

    // Check if the player has three of their marks in any winning combination
    for (const auto& pattern : winPatterns) {
        if (m_board[pattern[0]] == ac_player &&
            m_board[pattern[1]] == ac_player &&
            m_board[pattern[2]] == ac_player) {
            return true;    // A win is found
        }
    }
    return false;           // No win found
}

/**
 * Checks if the game is a draw.
 * A draw occurs if all cells are filled and no player has won.
 *
 * @return true if the game is a draw, false otherwise
 */
bool Board::checkDraw() const {
    // Check if all cells are filled (no empty cells left)
    return std::ranges::none_of(m_board, [](const CellState& cell) {
        return cell == CellState::EMPTY;  // If there's any empty cell, it's not a draw
    });
}

/**
 * Checks if a move is valid.
 * A move is valid if the corresponding cell is empty.
 *
 * @param ai_move The move number (1-9) to check
 * @return true if the move is valid (the cell is empty), false otherwise
 */
bool Board::checkMove(const int ai_move) const {
    // Check if the move is valid by checking if the chosen cell is empty
    return m_board[ai_move - 1] == CellState::EMPTY;  // Convert 1-based move to 0-based index
}

/**
 * Makes a move for a player by placing their symbol (X or O) in the specified cell.
 *
 * @param ac_player The player making the move (either X or O)
 * @param ai_move The move number (1-9) indicating where to place the player's symbol
 */
void Board::makeMove(const CellState ac_player, const int ai_move) {
    // Place the player's move in the specified position on the board
    m_board[ai_move - 1] = ac_player;  // Convert 1-based move to 0-based index
}

/**
 * Returns the symbol at a specific position on the board.
 * The position is specified by the row and column indices (0-based).
 *
 * @param ai_row The row index (0, 1, or 2)
 * @param a_col The column index (0, 1, or 2)
 * @return The symbol (X, O, or EMPTY) at the specified position
 */
CellState Board::getSymbol(const int ai_row, const int a_col) const {
    return m_board[ai_row * 3 + a_col];  // Convert row and column to 1D index
}