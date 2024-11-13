#include "HumanPlayer.h"
#include <iostream>
#include <limits>  // For std::numeric_limits to handle invalid input

/**
 * Allows the human player to make a move on the game board.
 * The player is prompted to enter a number corresponding to an empty cell.
 *
 * @param a_board The board where the move is to be made
 * @return true if the move is valid and successful, false otherwise
 */
bool HumanPlayer::makeMove(Board& a_board) {
    int move = 0;  // The move the player wants to make (1-9)

    std::cout << "Enter your move (1-9): ";  // Prompt the player to enter their move

    std::cin >> move;  // Read the player's input (move)

    // Check for invalid input (non-numeric or out of range)
    if (std::cin.fail()) {
        std::cin.clear();  // Clear the error flag on cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        std::cerr << "Invalid input! Please enter a number between 1 and 9.\n";
        return false;  // Return false if the input was invalid
    }

    // Check if the move is within the valid range and if the chosen cell is empty
    if (move < 1 || move > 9 || !a_board.checkMove(move)) {
        std::cerr << "Invalid move! The position is either out of range or already occupied.\n";
        return false;  // Return false if the move is out of range or the cell is occupied
    }

    // If the move is valid, make the move on the board
    a_board.makeMove(m_player, move);
    return true;  // Return true if the move was successfully made
}
