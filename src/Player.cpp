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
		// std::cout << "PLAYER: " << _hitbox.x << ", " << _hitbox.y << std::endl;
		// std::cout << "WALL: " << vec[i]->_hitbox.x << ", " << vec[i]->_hitbox.y << std::endl;
		if (vec[i] == nullptr)
			continue ;
		if (CheckCollisionRecs(this->_hitbox, vec[i]->_hitbox))
		{
			moveplayer = false;
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
	//movement

}