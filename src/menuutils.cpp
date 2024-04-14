#include "../inc/game.hpp"

void initMenu(Menu *menu, float *volume)
{
	bzero(menu, sizeof(*menu));

	menu->mastervolume = volume;

	menu->menu_state = MAIN;
	menu->playbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4, 500, 100};
	menu->settingsbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 150, 500, 100};
	menu->quitbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 300, 500, 100};
	menu->sliderbox = {SCREENWIDTH / 2 - 500, SCREENHEIGHT / 4, 1000, 10};
	menu->sliderpos = {(float)((menu->sliderbox.x + menu->sliderbox.width) / 100 * 42), menu->sliderbox.y + 5};
	menu->returnbox = menu->quitbox;
	menu->spell1.box = {SCREENWIDTH / 2 - 225, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell2.box = {SCREENWIDTH / 2 - 100, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell3.box = {SCREENWIDTH / 2 + 25, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell4.box = {SCREENWIDTH / 2 + 150, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->moneybox.box = {13, 13, 100, 100};
}