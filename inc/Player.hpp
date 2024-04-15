#pragma once

#include "game.hpp"


struct Player : public ObjFormat {
	Player(void);
	Player(Layer* layer);
	~Player(void);
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