#include "../inc/game.hpp"

// void DrawRectangleLines(int posX, int posY, int width, int height, Color color)

void drawMainMenu(MenuStruct menu)
{
	drawBoxWithText(menu.box1, 5, "PLAY GAME", MEDIUM_MENU_TEXT);
	drawBoxWithText(menu.box2, 5, "SETTINGS", MEDIUM_MENU_TEXT);
	drawBoxWithText(menu.box3, 5, "SETTINGS", MEDIUM_MENU_TEXT);
	
	//static text
	DrawText("GAME NAME", 20, 20, LARGE_MENU_TEXT, DARKGREEN);
    DrawText("PRESS ESC to EXIT", 120, 220, SMALL_MENU_TEXT, DARKGREEN);
}

void initMenu(Menu *menu)
{
	bzero(menu, sizeof(*menu));

	menu->box1 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4, 500, 100};
	menu->box2 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 150, 500, 100};
	menu->box3 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 300, 500, 100};
}

Vector2 getRectangleCenter(Rectangle rec)
{
	Vector2 vec = {rec.x + rec.width / 2, rec.y + rec.height / 2};
	return (vec);
}

Vector2 getTextCenter(std::string str, int font_size)
{
	Vector2 vec = {static_cast<float>(MeasureText(str.c_str(), font_size) / 2), static_cast<float>(font_size / 2)};
	return (vec);
}

void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size)
{
	Color boxcolor;
	if (CheckCollisionPointRec(GetMousePosition(), rec))
		boxcolor = ORANGE;
	else
		boxcolor = BLACK;

	Color textcolor;
	if (CheckCollisionPointRec(GetMousePosition(), rec))
		textcolor = ORANGE;
	else
		textcolor = DARKGREEN;

	DrawRectangleLinesEx(rec, thick, boxcolor);

	Vector2 boxcenter = getRectangleCenter(rec);
	Vector2 textcenter = getTextCenter(str.c_str(), font_size);
	DrawText(str.c_str(), boxcenter.x - textcenter.x, boxcenter.y - textcenter.y, font_size, textcolor);
}