#include "../inc/game.hpp"

Player::Player(void) {
	hp = 0;
	speed = 2;
	lookside = 0;
	_ptr = NULL;
}

Player::Player(Layer* layer) {
	hp = 0;
	speed = 2;
	lookside = 0;
	_ptr = layer;
}

Player::~Player(void) {
	
}

void Player::step(void)
{
	this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};
	Vector2 newPos = _pos;

	//movement
	if (IsKeyDown(keybord->forward))
	{
		_texture = &getTexture("player_up")[0];
		newPos.y -= speed;
	}
	if (IsKeyDown(keybord->backward))
	{
		_texture = &getTexture("player_down")[0];
		newPos.y += speed;
	}
	if (IsKeyDown(keybord->left))
	{
		_texture = &getTexture("player_left")[0];
		newPos.x -= speed;
	}
	if (IsKeyDown(keybord->right))
	{
		_texture = &getTexture("player_right")[0];
		newPos.x += speed;
	}

	//hitbox logic

	bool moveplayer = true;
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
			moveplayer = false;
			break ;
		}
	}

	if (moveplayer)
	{
		_pos = newPos;
	}
}