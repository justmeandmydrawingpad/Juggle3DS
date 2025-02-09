#ifndef NINJASTAR_H
#define NINJASTAR_H

class NinjaStar {
private:
    int xPosition;
    int yPosition;
    int xVelocity;
    int yVelocity;
    bool top;
    int touchXPositionOne;
    int touchYPositionOne;
    int touchXPositionTwo;
    int touchYPositionTwo;
    int touchXVelocity;
    int touchYVelocity;
    int pulse;
	double accelerationCounter;
	bool topCollided;
	bool leftCollided;
	bool rightCollided;

public:
    // Constructor
    NinjaStar(int startingXPos, int startingYPos);

    // Setters for velocity
    void setXVelocity(int xVelocity);
    void setYVelocity(int yVelocity);

    // Gravity effect on the NinjaStar
    void gravity(int touchX, int touchY);
	
	void simulateCollisions();

    // Move the NinjaStar based on its velocity
    void simulateVelocity();

    // Calculate the velocity of touch to be applied to the NinjaStar
    void fling(int touchX, int touchY, NinjaStar& star);
	
	//getters & setters
	bool getTop();
	int getXPosition();
	int getYPosition();

};

#endif // NINJASTAR_H
