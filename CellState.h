#ifndef CELLSTATE_H
#define CELLSTATE_H

#include <iostream>
#include <stdexcept>                             // For exception handling when encountering invalid states

// Enum class to represent the possible states of a cell on the TicTacToe board.
enum class CellState {
    EMPTY,                                        // The cell is empty (no player has made a move yet)
    X,                                            // The cell is occupied by player X
    O                                             // The cell is occupied by player O
};

// Inline constexpr function to convert a CellState to its corresponding string representation.
// This function maps CellState enum values to string literals for easy display.
[[nodiscard]] inline const char* cellToString(const CellState ac_Cell) {
    switch (ac_Cell) {
        case CellState::X:
            return "X";                            // If the cell is occupied by X, return "X"
        case CellState::O:
            return "O";                            // If the cell is occupied by O, return "O"
        case CellState::EMPTY:
            return "-";                            // If the cell is empty, return "-"
        default:
            // In case of an invalid CellState, throw an exception
                throw std::invalid_argument("Invalid CellState encountered");
    }
}

// Overload the output stream operator (<<) for the CellState type.
// This allows easy printing of CellState objects using std::cout, such as when printing the board.
inline std::ostream& operator<<(std::ostream& os, const CellState& ac_Cell) {
    try {
        return os << cellToString(ac_Cell);          // Convert the CellState to a string and output it
    } catch (const std::invalid_argument& e) {
        // If an invalid CellState is encountered, print an error message and return the output stream.
        std::cerr << "Error: " << e.what() << std::endl;
        return os;                                  // Return the output stream to allow further operations, even after an error
    }
}

#endif // CELLSTATE_H
