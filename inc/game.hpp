#pragma once

# if (__APPLE__ || __MACH__)
	#include "../lib/raylib/src/raylib.h"
# else
	#include <raylib.h>
# endif

//include
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include "ImageFormat.hpp"
#include "importTexture.hpp"
#include "MapOptions.hpp"
#include "Mountain.hpp"
#include "control.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "Gameloop.hpp"
#include "FireBall.hpp"
#include <chrono>

//include new obj






#define SCREENWIDTH 1366
#define SCREENHEIGHT 768
#define SMALL_MENU_TEXT 20
#define MEDIUM_MENU_TEXT 50
#define LARGE_MENU_TEXT 100
#define TEXTURE_SIZE 32
#define VIEW_DISTANCE 9
#define MAP_SIZE 80
#define FPS 60

//CUSTOM COLORS
#define LIGHTGRAYTRANS  CLITERAL(Color){ 200, 200, 200, 100 }   // Light Gray with transparancy
#define DARKGRAYTRANS  CLITERAL(Color){ 50, 50, 50, 100 }   // Light Gray with transparancy
#define WHITETRANS  CLITERAL(Color){ 255, 255, 255, 200 }   // Light Gray with transparancy


typedef enum GameScreen {TITLE = 0, GAMEPLAY, PAUSE, ENDING } GameScreen;
typedef enum MenuType {MAIN = 0, SETTINGS, GAME, PAUSEM, UPGRADE, END} MenuType;
typedef enum LayerH {FLOOR = 0, WALL, ENEMY, SPELL, PLAYER, MENUSPRITE} LayerH;

typedef struct TextureBox
{
	Rectangle box;
	Texture2D tex;
}	TextureBox;

typedef struct MenuStruct
{
	MenuType menu_state;
	float *mastervolume;
	int *dead;

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

	//Gameplay Boxes
	TextureBox spell1;
	TextureBox spell2;
	TextureBox spell3;
	TextureBox spell4;
	TextureBox moneybox;

	//Pause Menu
	Rectangle resumebox;
	Rectangle gamesetting;
	Rectangle tomenu_box;

	//Death Screen

} Menu;


//Texture
vec_tex &getTexture(const std::string& Texture, bool _free = false);
void	freeTexture2DMapOli(std::map<std::string, vector<Texture2D> >& map);
Player *getPlayer(Player *player = nullptr);

//Math position
float point_distance(Vector2 v1, Vector2 v2);
float point_direction(Vector2 point1, Vector2 point2);
void move_in_direction(Vector2& pos, float speed, float direction);

//Main Menu and its utils
int* deadState(int *var);
void drawUI(Menu *menu);
Vector2 getTextCenter(std::string str, int font_size);
void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size);
void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size, 
Color boxcolor, Color boxhighlight, Color textcolor, Color texthighlight);
void drawTextOnPoint(Vector2 pos, std::string str, int font_size, Color tcolor);
void initMenu(Menu *menu, float *volume);
void logicUI(Menu *menu, GameScreen *currentScreen);
void drawSlider(Menu *menu);
void sliderDetection(Menu *menu);
bool checkBoxCollision(Rectangle &box);

//Game menu
void drawGameMenu(Menu *menu);
void drawPauseMenu(Menu *menu);
void drawTextureBox(TextureBox &box);

//Pause menu