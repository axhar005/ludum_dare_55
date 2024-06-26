#include "../inc/game.hpp"

void initMenu(Menu *menu, float *volume)
{
	bzero(menu, sizeof(*menu));

	menu->mastervolume = volume;

	// MAIN UI
	menu->menu_state = MAIN;
	menu->playbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4, 500, 100};
	menu->settingsbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 150, 500, 100};
	menu->quitbox = {SCREENWIDTH / 2 + 100, SCREENHEIGHT / 4 + 300, 500, 100};
	menu->sliderbox = {SCREENWIDTH / 2 - 500, SCREENHEIGHT / 4, 1000, 10};
	menu->sliderpos = {(float)((menu->sliderbox.x + menu->sliderbox.width) / 100 * 42), menu->sliderbox.y + 5};
	menu->returnbox = menu->quitbox;

	//GAME UI
	menu->spell1.box = {SCREENWIDTH / 2 - 245, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell1.tex = getTexture("FireBallUI")[0];
	menu->spell2.box = {SCREENWIDTH / 2 - 115, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell2.tex = getTexture("IceSpikeUI")[0];
	menu->spell3.box = {SCREENWIDTH / 2 + 15, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell3.tex = getTexture("SlowZoneUI")[0];
	menu->spell4.box = {SCREENWIDTH / 2 + 145, (float)(SCREENHEIGHT / 100 * 93), 100, 100};
	menu->spell4.tex = getTexture("WindSlashUI")[0];
	menu->moneybox.box = {13, 13, 100, 100};
	menu->moneybox.tex = getTexture("SoulMoneyUI")[0];

	// PAUSE UI
	menu->resumebox = {SCREENWIDTH / 2 - 250, SCREENHEIGHT / 4 + 50, 500, 100};
	menu->gamesetting = {SCREENWIDTH / 2 - 250, SCREENHEIGHT / 4 + 200, 500, 100};
	menu->tomenu_box = {SCREENWIDTH / 2 - 250, SCREENHEIGHT / 4 + 350, 500, 100};

	// UPGRADE UI
}