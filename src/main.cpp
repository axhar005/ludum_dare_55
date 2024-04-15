#include "../inc/game.hpp"

Keys	keys;

float MasterVolume;

Player *getPLayer(Player *player){
	static Player *T = nullptr;
	static bool init;
	if (!init){
		T = player;
		init = true;
	}
	return T;
}

int main(void)
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "CATACOMB CONQUEST");
	SetMouseCursor(MOUSE_CURSOR_ARROW);
	getTexture("");

	GameScreen currentScreen = TITLE; //TODO: CHANGE THIS
	Menu menu;
	initMenu(&menu, &MasterVolume);
	int framesCounter = 0;          // Useful to count frames
	SetTargetFPS(60);               // Set desired framerate (frames-per-second)
	Layer	layers;                 //game obj live here
	InitMapLayer(layers);
	ObjFormat*	obj = new testStruct();
	AddImageFormatToLayer(layers, 0, obj);

	Map map(MapOptions(80, 80, 15, 20));

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

	// TODO: Unload all loaded data (textures, fonts, audio) here!

	CloseWindow();

	return 0;
}
