#pragma once

#include "game.hpp"


struct Enemy : public ObjFormat {
	Enemy(void);
	Enemy(Layer* layer);
	~Enemy(void);
	// var
	unsigned int		hp;
	unsigned int		speed;
	unsigned int		damage;
	short				lookside;
	vector<Texture2D>	walkL;
	vector<Texture2D>	walkR;
	vector<Texture2D>	walkUP;
	vector<Texture2D>	walkDW;
	Keys*				keybord;
	// ft
	void step(void) override;
};