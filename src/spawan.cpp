#include "../inc/game.hpp"

Spawner::Spawner(Layer* layer, ObjFormat* toSpawn) {
	_ptr = layer;
	if (toSpawn) {
		_toSpawn = *toSpawn;
		delete toSpawn;
	}
	_speed = 0;
	_layer = SPELL;
}

Spawner::~Spawner(void) {
}

void	Spawner::step(void) {
	static double	next = 0;
	if (_speed && next < GetTime()) {
		next += GetTime() + _speed;
		ObjFormat	*tmp = new ObjFormat();
		*tmp = _toSpawn;
		this->spawn(_layer, tmp, this->_pos);
	}
}