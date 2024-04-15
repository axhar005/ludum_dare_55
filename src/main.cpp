#include "../inc/game.hpp"

Keys	keys;

float MasterVolume;

Player *getPLayer(Player *player){
	static Player *T = nullptr;
	if (player)
		T = player;
	return T;
}

int main(void)
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "CATACOMB CONQUEST");
	SetMouseCursor(MOUSE_CURSOR_ARROW);

	GameScreen currentScreen = TITLE; //TODO: CHANGE THIS
	Layer	layers;                 //game obj live here
	InitMapLayer(layers);
	Menu menu;
	initMenu(&menu, &MasterVolume);
	int framesCounter = 0;          // Useful to count frames
	SetTargetFPS(60);               // Set desired framerate (frames-per-second)
	MasterVolume = 42;
	SetMasterVolume(MasterVolume);
	GameLoop(layers, START);
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		switch(currentScreen)
		{
			case TITLE: // MAIN MENU
			{

				logicUI(&menu, &currentScreen);
				
			} break;
			case GAMEPLAY:
			{
				logicUI(&menu, &currentScreen);
				if (IsKeyPressed(KEY_P) && menu.menu_state == GAME)
				{
					menu.menu_state = PAUSEM;
				}
				else if (IsKeyPressed(KEY_P) && menu.menu_state == PAUSEM)
				{
					menu.menu_state = GAME;
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
		//----------------------------------------------------------------------------------

		BeginDrawing();
			ClearBackground(RAYWHITE);
			//BeginMode2D(camera);
			DrawGrid(20, 10.0f); // Dessine une grille pour le référencement visuel
			//EndMode2D();
			switch(currentScreen)
			{
				case TITLE:
				{

					drawUI(&menu);

				} break;
				case GAMEPLAY:
				{
					ClearBackground(BLACK);
					if (IsKeyPressed(KEY_R) && menu.menu_state == GAME){
						GameLoop(layers, START);
					}
					else	
						GameLoop(layers, RUN);
					drawUI(&menu);
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

	CloseWindow();
	// TODO: Unload all loaded data (textures, fonts, audio) here!

	return 0;
}
