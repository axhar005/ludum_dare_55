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
	bool moveplayer = true;
	this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};

	//hitbox logic
	vector<ObjFormat*> vec = returnVecLayer(*_ptr, WALL);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr)
			continue ;
		//vec[i]->_hitbox
		//this->_hitbox
		if (CheckCollisionRecs(this->_hitbox, vec[i]->_hitbox))
		{
			moveplayer = false;
		}
	}

	//movement
	if (moveplayer)
	{
		if (IsKeyDown(keybord->forward))
		{
			_texture = &getTexture("player_up")[0];
			_pos.y -= speed;
		}
		if (IsKeyDown(keybord->backward))
		{
			_texture = &getTexture("player_down")[0];
			_pos.y += speed;
		}
		if (IsKeyDown(keybord->left))
		{
			_texture = &getTexture("player_left")[0];
			_pos.x -= speed;
		}
		if (IsKeyDown(keybord->right))
		{
			_texture = &getTexture("player_right")[0];
			_pos.x += speed;
		}
	}
}