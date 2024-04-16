#pragma once
#include "game.hpp"

struct FireBall : public ObjFormat {
	FireBall(void);
	FireBall(Layer* layer);
	~FireBall(void);
	void step(void) override;
	float _speed;
};