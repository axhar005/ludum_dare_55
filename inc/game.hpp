#pragma once

#include "../lib/raylib/src/raylib.h"
#include <iostream>
#include <string>
#include <cstdlib>

#define SCREENWIDTH 1366
#define SCREENHEIGHT 768
#define SMALL_MENU_TEXT 20
#define MEDIUM_MENU_TEXT 50
#define LARGE_MENU_TEXT 100

//CUSTOM COLORS
#define LIGHTGRAYTRANS  CLITERAL(Color){ 200, 200, 200, 100 }   // Light Gray with transparancy


typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, PAUSE, ENDING } GameScreen;
typedef enum MenuType {MAIN = 0, SETTINGS, GAME, PAUSEM, UPGRADE, END} MenuType;

typedef struct MenuStruct
{
	MenuType menu_state;
	float *mastervolume;

	// Main Menu Boxes
	Rectangle playbox;
	Rectangle settingsbox;
	Rectangle quitbox;

	//Settings Boxes
	Rectangle returnbox;

	//Slider Info
	Rectangle sliderbox;
	Vector2 sliderpos;
	bool moveSlider;
} Menu;

//Main Menu and its utils
void drawMainMenu(MenuStruct *menu);
Vector2 getTextCenter(std::string str, int font_size);
void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size);
void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size, 
Color boxcolor, Color boxhighlight, Color textcolor, Color texthighlight);
void drawTextOnPoint(Vector2 pos, std::string str, int font_size, Color tcolor);
void initMenu(Menu *menu, float *volume);
void buttonDetection(Menu *menu, GameScreen *currentScreen);
void drawSlider(Menu *menu);
void sliderDetection(Menu *menu);

//Game menu
void drawUI(Menu *menu);
void drawGameMenu(Menu *menu);

//Pause menu