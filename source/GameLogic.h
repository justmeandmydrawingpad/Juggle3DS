#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>

#include "NinjaStar.h"  // Assuming NinjaStar is another class

class GameLogic {
public:
    // Constructor declaration
    GameLogic();

    // Function to manage objects based on score
    void manageSpawns();

    // Getter for the starVector (constant reference to avoid unnecessary copying)
    std::vector<NinjaStar>& getStarVector();

private:
    int scoreCounter;
    std::vector<NinjaStar> starVector;  // Vector to hold the NinjaStar objects
};

#endif // GAMELOGIC_H
