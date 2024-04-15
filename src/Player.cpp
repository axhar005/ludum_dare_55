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
		_texture = animation(getTexture("player_up"), 0.1, 1);
		newPos.y -= speed;
	}
	if (IsKeyDown(keybord->backward))
	{
		_texture = animation(getTexture("player_down"), 0.1, 2);
		newPos.y += speed;
	}
	if (IsKeyDown(keybord->left))
	{
		_texture = animation(getTexture("player_left"), 0.1, 3);
		newPos.x -= speed;
	}
	if (IsKeyDown(keybord->right))
	{
		_texture = animation(getTexture("player_right"), 0.1, 4);
		newPos.x += speed;
	}
	if (newPos.x == _pos.x && newPos.y == _pos.y){
		_texture = animation(getTexture("player_standby"), 0.5, 5);
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