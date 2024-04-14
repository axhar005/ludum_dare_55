#include "../inc/game.hpp"

Keys	keys;

float MasterVolume;

vec_tex &getTexture(const std::string& Texture_){

	static std::map<std::string, vector<Texture2D> > T;
	static bool init;

	if (!init){

		std::map<std::string, std::vector<std::string> > Textures = {
			{"chat", {"antoine/cat.png", "antoine/cat2.png"}},
			{"soulsGui", {"Image/SoulMoney.png"}},
			{"glace", {"Image/IceSpike.png"}},
		};

		for (auto& pair : Textures) {
			std::string name = pair.first;
			for (auto& file : pair.second) {
				T[name].push_back(importImageToTexture2D(file.c_str()));
			}
		}
		init = true;
	}
	auto it = T.find(Texture_);
	if (it == T.end()){
		std::cout << "could not load texture: " << Texture_ << std::endl;
			throw std::runtime_error("could not load texture"); 
	}
	return it->second;
}

int main(void)
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "CATACOMB CONQUEST");
	SetMouseCursor(MOUSE_CURSOR_ARROW);
	// gettexture("chat");

	GameScreen currentScreen = TITLE; //TODO: CHANGE THIS
	Menu menu;
	initMenu(&menu, &MasterVolume);
	int framesCounter = 0;          // Useful to count frames
	SetTargetFPS(60);               // Set desired framerate (frames-per-second)
	Layer	layers;                 //game obj live here
	InitMapLayer(layers);
	// ObjFormat*	obj = new testStruct();
	// AddImageFormatToLayer(layers, 0, obj);

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

				buttonDetection(&menu, &currentScreen);
				
			} break;
			case GAMEPLAY:
			{
				// TODO: Update GAMEPLAY screen variables here!
				buttonDetection(&menu, &currentScreen);
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
			render(layers);
			//EndMode2D();
			switch(currentScreen)
			{
				case TITLE:
				{

					drawUI(&menu);

				} break;
				case GAMEPLAY:
				{
					// TODO: Draw GAMEPLAY screen here!
					ClearBackground(WHITE);
					GameLoop(layers, RUN);
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
