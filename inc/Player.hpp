#pragma once

#include "game.hpp"


struct Player : public ObjFormat {
	Player();
	~Player();
	// var
	unsigned int		hp;
	unsigned int		speed;
	short				lookside;
	vector<Texture2D>	walkL;
	vector<Texture2D>	walkR;
	vector<Texture2D>	walkUP;
	vector<Texture2D>	walkDW;
	Keys*				keybord;
	// ft
	void step(void) override;
};

//