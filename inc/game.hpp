#pragma once

#include "../lib/raylib/src/raylib.h"
#include <iostream>
#include <string>

#define SCREENWIDTH 1366
#define SCREENHEIGHT 768
#define SMALL_MENU_TEXT 20
#define MEDIUM_MENU_TEXT 50
#define LARGE_MENU_TEXT 100

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, PAUSE, ENDING } GameScreen;
typedef enum MenuType {MAIN = 0, SETTINGS = 1} MenuType;

typedef struct MenuStruct
{
	MenuType menu_state;
	Rectangle box1;
	Rectangle box2;
	Rectangle box3;
} Menu;

//Menu and Menu utils
void drawMainMenu(MenuStruct *menu);
Vector2 getTextCenter(std::string str, int font_size);
void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size);
void initMenu(Menu *menu);
int buttonDetection(Menu *menu, GameScreen *currentScreen);