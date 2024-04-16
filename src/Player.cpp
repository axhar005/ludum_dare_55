#include "../inc/game.hpp"

Player::Player(void) {
	hp = 100;
	speed = 2;
	lookside = 0;
	_ptr = NULL;
}

Player::Player(Layer* layer) {
	hp = 25 * 33;
	speed = 2;
	lookside = 0;
	_ptr = layer;
}

Player::~Player(void) {
	
}

void Player::step(void)
{
	this->_hitbox = {_pos.x + 4, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE - 8, TEXTURE_SIZE / 2};
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
	static int cooldown = 0;
	if (cooldown <= 0 && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
		Vector2 mouse = GetMousePosition();
		FireBall *f = new FireBall();
		f->_texture = &getTexture("fireball")[0];
		spawn(SPELL, (ObjFormat *)f, {_pos.x+8, _pos.y+8});
		f->_dir = point_direction({SCREENWIDTH/2, SCREENHEIGHT/2}, mouse);
		cooldown = 15;
	}
	if (cooldown > 0)
		cooldown--;

	//hitbox logic

	bool moveplayer = true;
	bool collision = false;
	Rectangle newHitbox = _hitbox;
	newHitbox.x = newPos.x + 4;
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

	//hp
	std::cout << hp << std::endl;
	if (hp < 33 || hp > 33 * 25)
	{
		int* isDead = deadState(NULL);
		*isDead = 1;
	}
}