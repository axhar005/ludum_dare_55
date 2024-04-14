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

}