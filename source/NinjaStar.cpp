#include <iostream>

#include "NinjaStar.h"


	NinjaStar::NinjaStar(int startingXPos, int startingYPos)
    : xPosition(startingXPos), yPosition(startingYPos),
      xVelocity(0), yVelocity(0), top(false), accelerationCounter(0), topCollided(true), leftCollided(false), rightCollided(false) {}


	
	void NinjaStar::fling(int touchX, int touchY, NinjaStar& star){
	
		if(pulse == 0){


			touchXPositionOne = touchX;
			touchYPositionOne = touchY;
			
			
			
		pulse = 1;
			

		}
		else{
			

			touchXPositionTwo = touchX;
			touchYPositionTwo = touchY;
			
			
			pulse = 0;
			
		
		if(touchXPositionOne != 0 && touchXPositionTwo != 0 && touchYPositionOne != 0 && touchYPositionTwo != 0)
		{
			touchXVelocity = touchXPositionOne - touchXPositionTwo;
			touchYVelocity = touchYPositionOne - touchYPositionTwo;
			
	}
		else{
			
			touchXVelocity = 0;
			touchXVelocity = 0;
		
		}
		
			if((touchX <= xPosition + 125 && touchX >= abs(xPosition - 75)) && (touchY <= yPosition + 125 && touchY >= abs(yPosition - 75))){
			

			//"lock" until screen not being touched
			//set velocity of shape equal to velocity of touch
			xVelocity = -touchXVelocity;
			yVelocity = -touchYVelocity;
		}
		}
		
		
		
	
	}

	void NinjaStar::gravity(int touchX, int touchY){
		
		if(accelerationCounter <= 1.0){
			accelerationCounter += 0.1;
		}
		else{
			accelerationCounter = 0.0;
		}
		
	//if not touching
		if(!((touchX <= xPosition + 125 && touchX >= abs(xPosition - 75)) && (touchY <= yPosition + 125 && touchY >= abs(yPosition - 75)))){
			yVelocity += (int)accelerationCounter;
		}
	}
	
	
	void NinjaStar::simulateCollisions(){
		
		if(yPosition <= -210){
			if(!topCollided){
				yVelocity = (int)((abs(yVelocity))/4);
				topCollided = true;
			}

		}
		else{
			topCollided = false;
		}
		if((top && (xPosition <= -10)) || ((!top) && (xPosition <= 20 ))){
			if(!leftCollided){
				xVelocity = (int)((abs(xVelocity)));
				yVelocity = (int)yVelocity/2;
				leftCollided = true;
			}
		}
		else{
			leftCollided = false;
		}
		if((top && (xPosition >= 325)) || ((!top) && (xPosition >= 285))){
			if(!rightCollided){
				xVelocity = (int)((-1 * abs(xVelocity)));
				yVelocity = (int)yVelocity/2;
				rightCollided = true;
			}
		}
		else{
			rightCollided = false;
		}
		
	}

	
	void NinjaStar::simulateVelocity(){
		
		xPosition += xVelocity;
		yPosition += yVelocity;
		
		//check screen
		if(yPosition <= 0 && !top){
			top = true;
		}
		else if(yPosition >= 0 && top){
			top = false;
		}
		
		
	}
	
	bool NinjaStar::getTop(){
		
		return top;
		
	}
	
	int NinjaStar::getXPosition(){
		
		return xPosition;
		
	}
	
	int NinjaStar::getYPosition(){
		
		return yPosition;
		
	}
		
	
	
