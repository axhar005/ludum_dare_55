#include "../inc/game.hpp"

// void DrawRectangleLines(int posX, int posY, int width, int height, Color color)

void drawMainMenuText(MenuStruct menu)
{
	menu.text1center.x = MeasureText("PLAY GAME", 40) / 2;
	menu.text1center.y = SMALL_MENU_TEXT / 2;


	Color text1color, text2color, text3color;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box1))
		text1color = ORANGE;
	else
		text1color = DARKGREEN;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box2))
		text2color = ORANGE;
	else
		text2color = DARKGREEN;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box3))
		text3color = ORANGE;
	else
		text3color = DARKGREEN;

	DrawText("PLAY GAME", SCREENWIDTH / 2 + 100 + 10, SCREENHEIGHT / 4 + 10, MEDIUM_MENU_TEXT, text1color);
	// DrawText("SETTINGS", 20, 20, 40, text2color);
	// DrawText("QUIT", 20, 20, 40, text3color);

	// static text
	DrawText("GAME NAME", 20, 20, LARGE_MENU_TEXT, DARKGREEN);
    DrawText("PRESS ESC to EXIT", 120, 220, SMALL_MENU_TEXT, DARKGREEN);
}

void drawMainMenu(MenuStruct menu)
{
	menu.box1 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4, 500, 100};
	menu.box2 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 150, 500, 100};
	menu.box3 = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 300, 500, 100};

	Color box1color, box2color, box3color;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box1))
		box1color = ORANGE;
	else
		box1color = BLACK;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box2))
		box2color = ORANGE;
	else
		box2color = BLACK;
	if (CheckCollisionPointRec(GetMousePosition(), menu.box3))
		box3color = ORANGE;
	else
		box3color = BLACK;

	DrawRectangleLines(SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4, 500, 100, box1color);
	DrawRectangleLines(SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 150, 500, 100, box2color);
	DrawRectangleLines(SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 300, 500, 100, box3color);
}