#include "../inc/game.hpp"

//Logic

void buttonDetection(Menu *menu, GameScreen *currentScreen)
{
	switch(menu->menu_state)
	{
		case MAIN:
		{
			if (CheckCollisionPointRec(GetMousePosition(), menu->playbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*currentScreen = GAMEPLAY;
				menu->menu_state = GAME;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), menu->settingsbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				menu->menu_state = SETTINGS;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), menu->quitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				//TODO: find out how to leave game
			}
		} break;
		case SETTINGS:
		{
			if (CheckCollisionPointRec(GetMousePosition(), menu->returnbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				menu->menu_state = MAIN;
			}
			sliderDetection(menu);
		} break;
		default: break;
	}
	
}

void sliderDetection(Menu *menu)
{
	Vector2 mouse = GetMousePosition();
	float volume = (float)((menu->sliderpos.x - menu->sliderbox.x) / 1000 * 100);

	if (CheckCollisionPointCircle(mouse, menu->sliderpos, 25) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		menu->moveSlider = true;
	}

	if (menu->moveSlider)
	{
		if (mouse.x > menu->sliderbox.x && mouse.x <= menu->sliderbox.x + menu->sliderbox.width)
		{
			menu->sliderpos.x = mouse.x;
			if (volume > 99.5f)
				*menu->mastervolume = 100;
			else
				*menu->mastervolume = (int)volume;
		}
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			menu->moveSlider = false;
		}
	}
}

// ------------------------------------------------------------------------------
// Rendering

void drawMainMenu(MenuStruct *menu)
{
	std::string volumestring = "VOLUME: " + std::to_string((int)*menu->mastervolume);
	switch(menu->menu_state)
	{
		case MAIN:
		{
			ClearBackground(GREEN);
			drawBoxWithText(menu->playbox, 5, "PLAY GAME", MEDIUM_MENU_TEXT);
			drawBoxWithText(menu->settingsbox, 5, "SETTINGS", MEDIUM_MENU_TEXT);
			drawBoxWithText(menu->quitbox, 5, "LEAVE GAME", MEDIUM_MENU_TEXT);

			//static text
			DrawText("CATACOMB CONQUEST", 20, 20, LARGE_MENU_TEXT, DARKGREEN);
			DrawText("PRESS ESC to EXIT", 120, 220, SMALL_MENU_TEXT, DARKGREEN);
		} break;
		case SETTINGS:
		{
			ClearBackground(BLUE);
			drawSlider(menu);
			drawBoxWithText(menu->returnbox, 5, "RETURN", MEDIUM_MENU_TEXT, DARKBLUE, ORANGE, DARKBLUE, ORANGE);

			//static text
			DrawText("SETTINGS", 20, 20, LARGE_MENU_TEXT, DARKBLUE);
			Vector2 volumetext = {SCREENWIDTH / 2, menu->sliderbox.y + 60};
			drawTextOnPoint(volumetext, volumestring, MEDIUM_MENU_TEXT, DARKBLUE);
		} break;
		default: break;
	}
}

void drawSlider(Menu *menu)
{
	DrawRectangleRounded(menu->sliderbox, 5, 0, DARKBLUE);

	DrawCircleV(menu->sliderpos, 20, WHITE);
	DrawCircleLinesV(menu->sliderpos, 20, BLACK);
	DrawRing(menu->sliderpos, 20, 25, 0, 360, 100, BLACK);
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

void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size) // for main menu
{
	Color boxcolor;
	if (CheckCollisionPointRec(GetMousePosition(), rec))
		boxcolor = ORANGE;
	else
		boxcolor = DARKGREEN;

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

void drawBoxWithText(Rectangle rec, float thick, std::string str, int font_size, 
Color boxcolor, Color boxhighlight, Color textcolor, Color texthighlight)
{
	Color bcolor;
	if (CheckCollisionPointRec(GetMousePosition(), rec))
		bcolor = boxhighlight;
	else
		bcolor = boxcolor;

	Color tcolor;
	if (CheckCollisionPointRec(GetMousePosition(), rec))
		tcolor = texthighlight;
	else
		tcolor = textcolor;

	DrawRectangleLinesEx(rec, thick, bcolor);

	Vector2 boxcenter = getRectangleCenter(rec);
	Vector2 textcenter = getTextCenter(str.c_str(), font_size);
	DrawText(str.c_str(), boxcenter.x - textcenter.x, boxcenter.y - textcenter.y, font_size, tcolor);
}

void drawTextOnPoint(Vector2 pos, std::string str, int font_size, Color tcolor)
{
	Vector2 textcenter = getTextCenter(str.c_str(), font_size);
	DrawText(str.c_str(), pos.x - textcenter.x, pos.y - textcenter.y, font_size, tcolor);
}