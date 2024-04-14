#pragma once

# if (__APPLE__ || __MACH__)
	#include "../lib/raylib/src/raylib.h"
# else
	#include <raylib.h>
# endif

#include "control.hpp"
#include "ImageFormat.hpp"
#include "importTexture.hpp"
#include "teststruct.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


#define SCREENWIDTH 1366
#define SCREENHEIGHT 768
#define SMALL_MENU_TEXT 20
#define MEDIUM_MENU_TEXT 50
#define LARGE_MENU_TEXT 100

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, PAUSE, ENDING } GameScreen;

typedef struct MenuStruct
{
	Rectangle box1;
	Rectangle box2;
	Rectangle box3;
	Vector2 box1center;
	Vector2 box2center;
	Vector2 box3center;

	Rectangle text1;
	Rectangle text2;
	Rectangle text3;
	Vector2 text1center;
	Vector2 text2center;
	Vector2 text3center;
} Menu;

Keys	keys;

void drawMainMenu(MenuStruct menu);
void drawMainMenuText(MenuStruct menu);
