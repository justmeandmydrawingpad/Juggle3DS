#include "GameLogic.h"
#include <cstdlib>
#include <ctime>

GameLogic::GameLogic() {
    scoreCounter = 0;

    // Initialize random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(0))); 
    
    // Generate random number between 6 and 305 (300 + 6)
    int randomNumber = std::rand() % 300 + 6;
    
    // Add first NinjaStar object to the vector
    starVector.push_back(NinjaStar(randomNumber, -290));
}

// Function to manage spawning based on score
void GameLogic::manageSpawns() {
    scoreCounter += 1;

    // Use a loop to spawn stars every 250 points starting from 500
    if (scoreCounter >= 500 && (scoreCounter - 500) % 250 == 0) {
        starVector.push_back(NinjaStar(std::rand() % 300 + 6, -290));
    }
}

std::vector<NinjaStar>& GameLogic::getStarVector() {
    return starVector;
}
