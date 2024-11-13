#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

// Class representing a human player in the Tic-Tac-Toe game
// Inherits from Player and allows the human player to make moves on the board.
class HumanPlayer final : public Player {
public:
    // Constructors and destructors
    // Default constructor, sets the symbol to EMPTY (no symbol initially)
    HumanPlayer() = default;
    // Constructor that initializes the player's symbol (X or O)
    explicit HumanPlayer(const CellState ac_player) : Player(ac_player) {}
    // Default destructor
    ~HumanPlayer() override = default;

    // FUnctions
    // Override the makeMove method to allow the human player to make a move
    bool makeMove(Board& a_board) override;

    // Override the getSymbol method to return the player's symbol (X or O)
    [[nodiscard]] CellState getSymbol() const override { return m_player; }
};

#endif // HUMANPLAYER_H
