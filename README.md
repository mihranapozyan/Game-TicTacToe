# Tic-Tac-Toe Game in C++

A simple **Tic-Tac-Toe** game implemented in **C++**, where a human player plays against an AI opponent. The AI uses the **Minimax algorithm** to make optimal decisions. The game allows alternating turns between a human player (Player X) and an AI (Player O), and now includes support for two human players.

This repository includes all the source code necessary to compile and run the game directly in your terminal.

## Features

- **Two players**: 
  - A human player (X) and an AI player (O) (Human vs AI mode).
  - Option to play with two human players (Human vs Human mode).
- **Minimax AI**: The AI opponent uses the Minimax algorithm to determine the best possible move (available in Human vs AI mode).
- **Game Modes**: 
  - **Human vs AI**: One player is human (X), and the other is AI (O).
  - **Human vs Human**: Both players are human, playing as X and O.
- **Terminal-based interface**: The game runs in the terminal with a text-based board.
- **Win Conditions**: Horizontal, vertical, or diagonal.
- **Draw Condition**: If no winner is found and no moves are left, the game ends in a draw.
- **Board Display**: After every move, the current board is printed along with available moves.

## How to Play

1. **Choose a game mode**: 
   - **Human vs AI**: Play against the AI.
   - **Human vs Human**: Play with a friend on the same device.

2. **Input your moves**: Enter a move by specifying the position on the board (1-9). The board layout will be shown at the start of the game, and after each move.

3. **Game flow**:
   - The game alternates turns between the players.
   - If playing against the AI, the AI will calculate the best move using the Minimax algorithm.
   - If both players are human, each player takes turns making their move.

4. **Winning the game**: 
   - The game ends when either player wins or the game ends in a draw (if the board is full and no one has won).

5. **Play again**: After the game ends, you can choose to start a new game.
