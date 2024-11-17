#include "Game.h"
#include <iostream>

int main() {
    // Prompt the user to select the game mode
    std::cout << "Select game mode:\n";
    std::cout << "1. Human vs. AI\n";
    std::cout << "2. Human vs. Human\n";  // Add newline for better readability
    int choice;
    std::cin >> choice;

    // Set the default game mode to Human vs. AI
    GameMode mode;

    // Choose the game mode based on user input
    if (choice == 1) {
        mode = GameMode::HumanVsAI;  // Player vs AI
    } else if (choice == 2) {
        mode = GameMode::HumanVsHuman;  // Player vs Player (Human)
    } else {
        // If the input is invalid, print an error and default to Human vs. AI
        std::cerr << "Invalid choice! Defaulting to Human vs. AI.\n";
        mode = GameMode::HumanVsAI;
    }

    // Create a Game object with the chosen game mode
    Game game(mode);

    // Start the game by calling the play method
    game.play();

    return 0;
}
