#include "../inc/game.hpp"

void drawGameMenu(Menu *menu)
{
	drawTextureBox(menu->spell1);
	drawTextureBox(menu->spell2);
	drawTextureBox(menu->spell3);
	drawTextureBox(menu->spell4);
	drawTextureBox(menu->moneybox);
}

void drawPauseMenu(Menu *menu)
{
	DrawRectangle(0, 0, SCREENWIDTH, SCREENHEIGHT, DARKGRAYTRANS);

	//text
	Vector2 textpos = {SCREENWIDTH / 2, SCREENHEIGHT / 4};
	drawTextOnPoint(textpos, "PAUSE", LARGE_MENU_TEXT, WHITE);

	//buttons
	drawBoxWithText(menu->resumebox, 5, "RESUME", MEDIUM_MENU_TEXT, LIGHTGRAY, ORANGE, LIGHTGRAY, ORANGE);
	drawBoxWithText(menu->gamesetting, 5, "SETTINGS", MEDIUM_MENU_TEXT, LIGHTGRAY, ORANGE, LIGHTGRAY, ORANGE);
	drawBoxWithText(menu->tomenu_box, 5, "RETURN TO MENU", MEDIUM_MENU_TEXT, LIGHTGRAY, ORANGE, LIGHTGRAY, ORANGE);

	// void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size, 
	// Color boxcolor, Color boxhighlight, Color textcolor, Color texthighlight)
}

void drawTextureBox(TextureBox &box)
{
	DrawRectangleRounded(box.box, 0.2, 0, LIGHTGRAYTRANS);
	DrawRectangleRoundedLines(box.box, 0.2, 0, 5, DARKGRAYTRANS);
	DrawTexture(box.tex, box.box.x, box.box.y, WHITE);
	//add sprite with box.tex
	
}