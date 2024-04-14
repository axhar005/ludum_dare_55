#include "../inc/game.hpp"

float MasterVolume;

int main(void)
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetMouseCursor(MOUSE_CURSOR_ARROW);

	GameScreen currentScreen = TITLE; //TODO: CHANGE THIS
	Menu menu;
	initMenu(&menu, &MasterVolume);
	int framesCounter = 0;          // Useful to count frames
	SetTargetFPS(60);               // Set desired framerate (frames-per-second)
	//
	Layer	layers;                 //game obj live here
	InitMapLayer(layers);
	// Texture2D cat = importImageToTexture2D("antoine/cat.png");
	//ObjFormat*	obj = new ObjFormat(cat);
	ObjFormat*	obj1 = new testStruct();
	//AddImageFormatToLayer(layers, 0, obj);
	AddImageFormatToLayer(layers, 0, obj1);
	//
	MasterVolume = 42;
	SetMasterVolume(MasterVolume);

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		switch(currentScreen)
		{
			case LOGO:
			{
				// TODO: Update LOGO screen variables here!

				framesCounter++;    // Count frames

				// Wait for 2 seconds (120 frames) before jumping to TITLE screen
				if (framesCounter > 120)
				{
					currentScreen = TITLE;
				}
			} break;
			case TITLE: // MAIN MENU
			{

				buttonDetection(&menu, &currentScreen);
				
			} break;
			case GAMEPLAY:
			{
				// TODO: Update GAMEPLAY screen variables here!

				if (IsKeyPressed(KEY_P))
				{
					std::cout << "PAUSE" << std::endl;
				}
			} break;
			case PAUSE:
			{

			} break;
			case ENDING:
			{
				// TODO: Update ENDING screen variables here!

				// Press enter to return to TITLE screen
				if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
				{
					currentScreen = TITLE;
				}
			} break;
			default: break;
		}

		// Draw
		BeginDrawing();

			ClearBackground(RAYWHITE);
			render(layers);
			switch(currentScreen)
			{
				case LOGO:
				{
					// TODO: Draw LOGO screen here!
					DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
					DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

				} break;
				case TITLE:
				{

					drawMainMenu(&menu);

				} break;
				case GAMEPLAY:
				{
					// TODO: Draw GAMEPLAY screen here!
					ClearBackground(WHITE);
					drawUI(&menu);
					//gameplay
					//menus
				} break;
				case PAUSE:
				{
					
				} break;
				case ENDING:
				{
					// TODO: Draw ENDING screen here!
					ClearBackground(BLUE);
					DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
					DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

				} break;
				default: break;
			}

		EndDrawing();
	}

	// De-Initialization

	// TODO: Unload all loaded data (textures, fonts, audio) here!

	CloseWindow();

	return 0;
}