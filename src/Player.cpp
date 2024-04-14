#include "../inc/game.hpp"

Player::Player(void) {
	hp = 0;
	speed = 2;
	lookside = 0;
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