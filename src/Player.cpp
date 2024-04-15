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

void Player::step(void) {
	this->_hitbox = {_pos.x, _pos.y, TEXTURE_SIZE, TEXTURE_SIZE};

	if (IsKeyDown(keybord->forward))
		_pos.y -= speed;
	if (IsKeyDown(keybord->backward))
		_pos.y += speed;
	if (IsKeyDown(keybord->left))
		_pos.x -= speed;
	if (IsKeyDown(keybord->right))
		_pos.x += speed;

	//hitbox logic
	//bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);

}