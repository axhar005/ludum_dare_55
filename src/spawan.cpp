#include "../inc/game.hpp"


Spawner::Spawner(Layer* layer, Enemy* toSpawn) {
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
		next = GetTime() + _speed;
		Enemy	*tmp = new Enemy();
		*tmp = _toSpawn;
		this->spawn(_layer, tmp, this->_pos);
		this->_pos.x = (GetRandomValue(1, MAP_SIZE - 1) * TEXTURE_SIZE);

		this->_pos.y = (GetRandomValue(1, MAP_SIZE - 1) * TEXTURE_SIZE);
	}
}