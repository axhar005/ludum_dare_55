#include "../inc/game.hpp"

int main(void)
{

	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetMouseCursor(MOUSE_CURSOR_ARROW);

	GameScreen currentScreen = TITLE; //TODO: CHANGE THIS

	// DECLARE VARIABLES HERE -------------------------------------------
	Menu menu;
	initMenu(&menu);
	int framesCounter = 0;          // Useful to count frames
	SetTargetFPS(60);               // Set desired framerate (frames-per-second)

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
			case TITLE:
			{
				// TODO: Update TITLE screen variables here!
				// Press enter to change to GAMEPLAY screen
				
			} break;
			case GAMEPLAY:
			{
				// TODO: Update GAMEPLAY screen variables here!

				// Press enter to change to ENDING screen
				if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
				{
					currentScreen = ENDING;
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
					// TODO: Draw TITLE screen here!
					ClearBackground(GREEN);
					drawMainMenu(menu);
					
				} break;
				case GAMEPLAY:
				{
					// TODO: Draw GAMEPLAY screen here!
					ClearBackground(ORANGE);
					DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
					DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

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

	CloseWindow();        // Close window and OpenGL context

	return 0;
}