#pragma once

#include "game.hpp"

struct Spawner : public ObjFormat {
	Spawner(Layer* layer, ObjFormat *toSpawn);
	~Spawner(void);
	// var
	double				_speed;
	ObjFormat			_toSpawn;
	int					_layer;
	// ft
	void step(void) override;
};

