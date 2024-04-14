#include "../inc/game.hpp"

Player::Player(void) {
	hp = 0;
	speed = 10;
	lookside = 0;
}

Player::~Player(void) {
	
}

void Player::step(void) {
	if (IsKeyDown(keybord->forward))
		vec2.y -= speed;
	if (IsKeyDown(keybord->backward))
		vec2.y += speed;
	if (IsKeyDown(keybord->left))
		vec2.x -= speed;
	if (IsKeyDown(keybord->right))
		vec2.x += speed;
}