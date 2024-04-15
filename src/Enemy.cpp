#include "../inc/game.hpp"

Enemy::Enemy(void) {
	hp = 0;
	speed = 1;
	lookside = 0;
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
	this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};
	Vector2 newPos = _pos;


	//movement
	vector<ObjFormat*> pvec = returnVecLayer(*_ptr, PLAYER);
	_dir = point_direction(_pos, pvec[0]->_pos);
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

	// if (pvec[0]->_pos.y > _pos.y)
	// {
	// 	_texture = &getTexture("enemy_up")[0];
	// 	newPos.y -= speed;
	// }
	// if (pvec[0]->_pos.y < _pos.y)
	// {
	// 	_texture = &getTexture("enemy_down")[0];
	// 	newPos.y += speed;
	// }
	// if (pvec[0]->_pos.x > _pos.x)
	// {
	// 	_texture = &getTexture("enemy_left")[0];
	// 	newPos.x -= speed;
	// }
	// if (pvec[0]->_pos.x < _pos.x)
	// {
	// 	_texture = &getTexture("enemy_right")[0];
	// 	newPos.x += speed;
	// }


	//hitbox logic

	bool move = true;
	bool collision = false;
	Rectangle newHitbox = _hitbox;
	newHitbox.x = newPos.x;
	newHitbox.y = newPos.y + TEXTURE_SIZE / 2;

	vector<ObjFormat*> vec = returnVecLayer(*_ptr, WALL);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr)
			continue ;
		collision = CheckCollisionRecs(newHitbox, vec[i]->_hitbox);
		if (collision)
		{
			move = false;
			break ;
		}
	}

	// collision with other enemy
	vector<ObjFormat*> evec = returnVecLayer(*_ptr, ENEMY);
	for (int i = 0; i < evec.size(); i++)
	{
		if (evec[i] == this)
			continue ;
		collision = CheckCollisionRecs(newHitbox, evec[i]->_hitbox);
		if (collision)
		{
			move = false;
			break ;
		}
	}

	if (move)
	{
		_pos = newPos;
	}
}