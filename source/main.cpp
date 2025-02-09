// Simple citro2d untextured shape example
#include <citro2d.h>

#include <cstring>   // C++ version of <string.h>
#include <iostream>  // C++ version of <stdio.h>
#include <cstdlib>   // C++ version of <stdlib.h>
#include <cmath>

#include "NinjaStar.h"

#include "GameLogic.h"


#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

//colors
u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
u32 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
u32 clrLightBlue = C2D_Color32(0x80, 0x80, 0xFF, 0xFF);


u32 clrCircle1 = C2D_Color32(0xFF, 0x00, 0xFF, 0xFF);
u32 clrCircle2 = C2D_Color32(0xFF, 0xFF, 0x00, 0xFF);
u32 clrCircle3 = C2D_Color32(0x00, 0xFF, 0xFF, 0xFF);

u32 clrSolidCircle = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF);

u32 clrTri1 = C2D_Color32(0xFF, 0x15, 0x00, 0xFF);
u32 clrTri2 = C2D_Color32(0x27, 0x69, 0xE5, 0xFF);

u32 clrRec1 = C2D_Color32(0x9A, 0x6C, 0xB9, 0xFF);
u32 clrRec2 = C2D_Color32(0xFF, 0xFF, 0x2C, 0xFF);
u32 clrRec3 = C2D_Color32(0xD8, 0xF6, 0x0F, 0xFF);
u32 clrRec4 = C2D_Color32(0x40, 0xEA, 0x87, 0xFF);

u32 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68);



void draw(NinjaStar star, int topAdder, int rightAdder){
	//topAdder adds -240 or 0 depending on top or bottom
		
	C2D_DrawCircleSolid(
	(star.getXPosition() + rightAdder), 
	(star.getYPosition() + topAdder), 
	0, 
	30, 
	clrRed
	);
	
	/*
	C2D_DrawRectangle(
		(star.getRectangleXPosition() + rightAdder), //x: X-coordinate of the top-left corner (50 pixels from the right edge of the screen)
		(star.getRectangleYPosition() + topAdder),                 // y: Y-coordinate of the top-left corner (at the top of the screen)
		0,                 // z: Z-coordinate (depth), drawing at the default depth (0)
		50,                // width: The width of the rectangle (50 pixels)
		50,                // height: The height of the rectangle (50 pixels)
		clrRec1,           // color1: Color of the top-left corner
		clrRec2,           // color2: Color of the top-right corner
		clrRec3,           // color3: Color of the bottom-left corner
		clrRec4            // color4: Color of the bottom-right corner
		);
	*/
	
	
}



//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {

	GameLogic game;

	
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	
	
	
	u32 kDownOld = 0, kHeldOld = 0, kUpOld = 0; //In these variables there will be information about keys detected in the previous frame

	// Create screens
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	

	

	// Main loop
	while (aptMainLoop())
	{	
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
		//hidKeysHeld returns information about which buttons have are held down in this frame
		u32 kHeld = hidKeysHeld();
		//hidKeysUp returns information about which buttons have been just released
		u32 kUp = hidKeysUp();
		
		
		
		
		
		if (kDown & KEY_START){
			break; // break in order to return to hbmenu
		}

		touchPosition touch;

		//Read the touch screen coordinates
		hidTouchRead(&touch);
		

		//game spawns & logic
		game.manageSpawns();

		
		for (NinjaStar& star : game.getStarVector()) {
			star.fling(touch.px, touch.py, star);
			
			star.simulateCollisions();
			
			star.gravity(touch.px, touch.py);
		
			//sets if on top as well
			star.simulateVelocity();

		}


		
		
		//top screen render here
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);
		
		//bg
		C2D_DrawRectangle(0, 0, -1, 500, 500, clrLightBlue, clrLightBlue, clrLightBlue, clrLightBlue);
		
		for (NinjaStar& star : game.getStarVector()) {
		if(star.getTop()){
			draw(star, 240, 40);
		}
		}
		
		C3D_FrameEnd(0);
		
		

		
		//bottom screen render here
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(bottom, clrClear);
		C2D_SceneBegin(bottom);
		
		C2D_DrawRectangle(0, 0, -1, 500, 500, clrLightBlue, clrLightBlue, clrLightBlue, clrLightBlue);
		
		for (NinjaStar& star : game.getStarVector()) {
		if(!star.getTop()){
			draw(star, 0, 0);
		}
		}
		

		C3D_FrameEnd(0);
		
		
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}



