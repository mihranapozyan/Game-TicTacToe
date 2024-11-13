#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Board.h"

// Class representing an AI player in the Tic-Tac-Toe game
// Inherits from Player and uses the minimax algorithm to make optimal moves.
class AIPlayer final : public Player {
public:
    // Constructor initializes the AI player's symbol (usually 'O')
    explicit AIPlayer(const CellState ac_player) : Player(ac_player) {}

    // Override the makeMove method to allow the AI player to make a move
    bool makeMove(Board &a_board) override;

    // Override the getSymbol method to return the AI player's symbol (X or O)
    [[nodiscard]] CellState getSymbol() const override { return m_player; }

private:
    // Function to evaluate the current board state: win for AI, loss for player, or draw
    int evaluateBoard(const Board &a_board) const;

    // Recursive minimax algorithm function to explore possible moves
    int minimax(Board &a_board, int ai_depth, bool ab_isMaximizingPlayer);

    // Function to find the best move for the AI using the minimax algorithm
    int findBestMove(Board &a_board);
};

#endif // AIPLAYER_H