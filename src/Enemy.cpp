#include "../inc/game.hpp"

Enemy::Enemy(void) {
	hp = 0;
	speed = 1;
	lookside = 0;
	damage = 1;
	_ptr = NULL;
}

Enemy::Enemy(Layer* layer) {
	hp = 0;
	speed = 1;
	lookside = 0;
	_ptr = layer;
}

Enemy::~Enemy(void) {
	
}

void Enemy::step(void)
{
	this->_hitbox = {_pos.x + 16, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE / 2, TEXTURE_SIZE / 2};
	Vector2 newPos = _pos;


	//movement
	Player *player = getPlayer();
	_dir = point_direction(_pos, player->_pos);
	move_in_direction(newPos, speed, _dir);

	if (_dir >= 315 || _dir < 45)
	{
		_texture = &getTexture("enemy_down")[0];
	}
	if (_dir >= 45 && _dir < 135)
	{
		_texture = &getTexture("enemy_left")[0];
	}
	if (_dir >= 135 && _dir < 225)
	{
		_texture = &getTexture("enemy_up")[0];
	}
	if (_dir >= 225 && _dir < 315)
	{
		_texture = &getTexture("enemy_right")[0];
	}

	//hitbox logic

	bool move = true;
	bool collision = false;
	Rectangle newHitbox = _hitbox;
	newHitbox.x = newPos.x + 16;
	newHitbox.y = newPos.y + TEXTURE_SIZE / 2;

	//wall collision
	vector<ObjFormat*> vec = returnVecLayer(*_ptr, WALL);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr)
			continue ;
		collision = CheckCollisionRecs(newHitbox, vec[i]->_hitbox);
		if (collision)
		{
			kill();
			move = false;
			break ;
		}
	}
	
	// hit player
	collision = CheckCollisionRecs(newHitbox, player->_hitbox);
	if (collision)
	{
		player->hp -= damage;
		kill();
	}

	if (move)
	{
		_pos = newPos;
	}
}