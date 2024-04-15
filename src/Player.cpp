#include "../inc/game.hpp"

Enemy::Enemy(void) {
	hp = 0;
	speed = 2;
	lookside = 0;
	_ptr = NULL;
}

Enemy::Enemy(Layer* layer) {
	hp = 0;
	speed = 2;
	lookside = 0;
	_ptr = layer;
}

Enemy::~Enemy(void) {
	
}

void Enemy::step(void)
{
	this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};
	Vector2 newPos = _pos;

	// //movement
	// if (IsKeyDown(keybord->forward))
	// {
	// 	_texture = &getTexture("player_up")[0];
	// 	newPos.y -= speed;
	// }
	// if (IsKeyDown(keybord->backward))
	// {
	// 	_texture = &getTexture("player_down")[0];
	// 	newPos.y += speed;
	// }
	// if (IsKeyDown(keybord->left))
	// {
	// 	_texture = &getTexture("player_left")[0];
	// 	newPos.x -= speed;
	// }
	// if (IsKeyDown(keybord->right))
	// {
	// 	_texture = &getTexture("player_right")[0];
	// 	newPos.x += speed;
	// }

	//hitbox logic

	bool moveplayer = true;
	bool collision = false;
	Rectangle boxCollision;
	Rectangle newHitbox = _hitbox;
	newHitbox.x = newPos.x;
	newHitbox.y = newPos.y + TEXTURE_SIZE / 2;

	vector<ObjFormat*> vec = returnVecLayer(*_ptr, WALL);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "PLAYERPOS: " << newHitbox.x << ", " << newHitbox.y << std::endl;
		std::cout << "WALLPOS: " << vec[i]->_hitbox.x << ", " << vec[i]->_hitbox.y << std::endl;
		if (vec[i] == nullptr)
			continue ;
		collision = CheckCollisionRecs(newHitbox, vec[i]->_hitbox);
		if (collision)
		{
			moveplayer = false;
			break ;
		}
	}
	int z = 0;
	if (moveplayer)
	{
		if (IsKeyDown(keybord->forward))
		{
			_texture = animation(getTexture("player_up"), 0.1, z);
			_pos.y -= speed;
			z = 1;
		}
		else if (IsKeyDown(keybord->backward))
		{
			_texture = animation(getTexture("player_down"), 0.1, z);
			_pos.y += speed;
			z = 2;
		}
		else if (IsKeyDown(keybord->left))
		{
			_texture = animation(getTexture("player_left"), 0.1, z);
			_pos.x -= speed;
			z = 3;
		}
		else if (IsKeyDown(keybord->right))
		{
			_texture = animation(getTexture("player_right"), 0.1, z);
			_pos.x += speed;
			z = 4;
		}
		else {
			z = 5;
			_texture = animation(getTexture("player_standby"), 0.5, z);
		}
	}
}