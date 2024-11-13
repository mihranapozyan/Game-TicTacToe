#ifndef PLAYER_H
#define PLAYER_H

#include "CellState.h"
#include "Board.h"

// Abstract base class representing a player (either human or AI) in the Tic-Tac-Toe game.
// This class provides a common interface for different types of players, whether they are human or AI.
class Player {
public:
    virtual ~Player() = default;  // Virtual destructor ensures proper cleanup of derived classes

    // Pure virtual function that must be implemented by derived classes to make a move
    // on the given board. This method defines how a player interacts with the board.
    virtual bool makeMove(Board& a_board) = 0;

    // Virtual function to get the symbol (X or O) of the player.
    // This method is used to identify the player (X or O).
    [[nodiscard]] virtual CellState getSymbol() const = 0;

protected:
    CellState m_player;  // The symbol representing this player (either X or O)

    // Protected constructor allows initialization of the player's symbol.
    // This constructor is only accessible from derived classes (HumanPlayer, AIPlayer, etc.).
    explicit Player(CellState ac_player) : m_player(ac_player) {}
};

#endif // PLAYER_H
