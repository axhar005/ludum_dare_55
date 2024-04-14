#include "../inc/game.hpp"

void drawUI(Menu *menu)
{
	switch(menu->menu_state)
	{
		case GAME:
		{
			drawGameMenu(menu);
		} break;
		case PAUSEM:
		{
			
		} break;
		case END:
		{

		} break;
		default: break;
	}
}

void drawGameMenu(Menu *menu)
{
	drawTextureBox(menu->spell1);
	drawTextureBox(menu->spell2);
	drawTextureBox(menu->spell3);
	drawTextureBox(menu->spell4);
	drawTextureBox(menu->moneybox);
}

void drawTextureBox(TextureBox &box)
{
	//DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);              // Draw rectangle with rounded edges
    //DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, float lineThick, Color color); // Draw rectangle with rounded edges outline
	DrawRectangleRounded(box.box, 0.2, 0, LIGHTGRAYTRANS);
	DrawRectangleRoundedLines(box.box, 0.2, 0, 5, DARKGRAYTRANS);
	//add sprite with box.tex
	
}