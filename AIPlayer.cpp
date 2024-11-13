#include "AIPlayer.h"
#include "Board.h"
#include <iostream>
#include <algorithm>

constexpr int WIN_SCORE = 10;   // AI wins
constexpr int LOSE_SCORE = -10; // Player wins
constexpr int DRAW_SCORE = 0;   // Draw

/**
 * Evaluates the current state of the board.
 * The function returns a score based on the state:
 * +10 for AI's victory, -10 for player's victory, and 0 for a draw.
 *
 * @param a_board The current game board
 * @return An integer score representing the board's state
 */
int AIPlayer::evaluateBoard(const Board &a_board) const {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (a_board.getSymbol(i, 0) == a_board.getSymbol(i, 1) && a_board.getSymbol(i, 1) == a_board.getSymbol(i, 2)) {
            if (a_board.getSymbol(i, 0) == m_player) return WIN_SCORE;  // AI wins
            else if (a_board.getSymbol(i, 0) != CellState::EMPTY) return LOSE_SCORE; // Player wins
        }

        // Check columns
        if (a_board.getSymbol(0, i) == a_board.getSymbol(1, i) && a_board.getSymbol(1, i) == a_board.getSymbol(2, i)) {
            if (a_board.getSymbol(0, i) == m_player) return WIN_SCORE;  // AI wins
            else if (a_board.getSymbol(0, i) != CellState::EMPTY) return LOSE_SCORE; // Player wins
        }
    }

    // Check diagonals
    if (a_board.getSymbol(0, 0) == a_board.getSymbol(1, 1) && a_board.getSymbol(1, 1) == a_board.getSymbol(2, 2)) {
        if (a_board.getSymbol(0, 0) == m_player) return WIN_SCORE;  // AI wins
        else if (a_board.getSymbol(0, 0) != CellState::EMPTY) return LOSE_SCORE; // Player wins
    }
    if (a_board.getSymbol(0, 2) == a_board.getSymbol(1, 1) && a_board.getSymbol(1, 1) == a_board.getSymbol(2, 0)) {
        if (a_board.getSymbol(0, 2) == m_player) return WIN_SCORE;  // AI wins
        else if (a_board.getSymbol(0, 2) != CellState::EMPTY) return LOSE_SCORE; // Player wins
    }

    // If no winner, return 0 for a draw
    return DRAW_SCORE;
}

/**
 * Minimax algorithm to calculate the optimal move for the AI player.
 * This is a recursive function that explores all possible moves and returns
 * a score based on whether the AI or player wins, or if the game ends in a draw.
 *
 * @param a_board The current game board
 * @param ai_depth The current depth of recursion (how many moves ahead)
 * @param ab_isMaximizingPlayer Boolean flag to indicate if the current player is the maximizing player (AI)
 * @return The score of the board state, used to determine the best move
 */
int AIPlayer::minimax(Board &a_board, const int ai_depth, const bool ab_isMaximizingPlayer) {
    const int li_score = evaluateBoard(a_board);  // Get the current score of the board state
    if (li_score == WIN_SCORE) return li_score - ai_depth;  // AI wins, prefer faster wins
    if (li_score == LOSE_SCORE) return li_score + ai_depth;  // Player wins, prefer slower losses
    if (a_board.checkDraw()) return DRAW_SCORE;  // Draw condition

    if (ab_isMaximizingPlayer) {
        int li_best = -1000;  // Start with the worst possible score for AI

        // Explore all possible moves for the AI (maximizing player)
        for (int i = 1; i <= 9; i++) {
            if (a_board.checkMove(i)) {
                a_board.makeMove(m_player, i);  // Make the AI move
                li_best = std::max(li_best, minimax(a_board, ai_depth + 1, false));  // Call minimax recursively for the opponent
                a_board.makeMove(CellState::EMPTY, i);  // Undo the move
            }
        }
        return li_best;
    } else {
        int li_best = 1000;  // Start with the worst possible score for the player

        // Explore all possible moves for the player (minimizing player)
        for (int i = 1; i <= 9; i++) {
            if (a_board.checkMove(i)) {
                a_board.makeMove(CellState::X, i);  // Make the player move
                li_best = std::min(li_best, minimax(a_board, ai_depth + 1, true));  // Call minimax recursively for AI
                a_board.makeMove(CellState::EMPTY, i);  // Undo the move
            }
        }
        return li_best;
    }
}

/**
 * Finds the best move for the AI using the minimax algorithm.
 * It evaluates all possible moves and returns the one with the best score.
 *
 * @param a_board The current game board
 * @return The best move for the AI (position between 1 and 9)
 */
int AIPlayer::findBestMove(Board &a_board) {
    int li_bestVal = -1000;  // Start with the worst possible score for AI
    int li_bestMove = -1;

    // Explore all possible moves for the AI and select the one with the best score
    for (int i = 1; i <= 9; i++) {
        if (a_board.checkMove(i)) {
            a_board.makeMove(m_player, i);  // Make the AI move
            const int li_moveVal = minimax(a_board, 0, false);  // Evaluate the move
            a_board.makeMove(CellState::EMPTY, i);  // Undo the move
            if (li_moveVal > li_bestVal) {
                li_bestMove = i;  // Update best move if this one is better
                li_bestVal = li_moveVal;  // Update best value
            }
        }
    }

    return li_bestMove;  // Return the best move found
}

/**
 * Makes the best possible move for the AI on the board.
 * This method uses the minimax algorithm to find the best move and then applies it.
 *
 * @param a_board The board where the AI will make its move
 * @return true if the AI successfully made a move, false otherwise
 */
bool AIPlayer::makeMove(Board &a_board) {
    const int li_bestMove = findBestMove(a_board);  // Get the best move

    // Make the move at the best position found
    a_board.makeMove(m_player, li_bestMove);
    std::cout << "AI makes a move at position: " << li_bestMove << std::endl;
    return true;  // Return true to indicate the move was successful
}
