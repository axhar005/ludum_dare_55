#include "../inc/game.hpp"

Player::Player(void) {
	hp = 0;
	speed = 10;
	lookside = 0;
	hitbox = {_pos.x - TEXTURE_SIZE / 2, _pos.y - TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE};
}

Player::~Player(void) {
	
}

void Player::step(void) {
	if (IsKeyDown(keybord->forward))
		_pos.y -= speed;
	if (IsKeyDown(keybord->backward))
		_pos.y += speed;
	if (IsKeyDown(keybord->left))
		_pos.x -= speed;
	if (IsKeyDown(keybord->right))
		_pos.x += speed;
}