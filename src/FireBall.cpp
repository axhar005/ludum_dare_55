#include "../inc/game.hpp"

FireBall::FireBall(void) {
}

FireBall::~FireBall(void) {
	
}

void FireBall::step(void)
{
	this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};
	Vector2 newPos = _pos;

	//movement
		

	//hitbox logic
	bool moveplayer = true;
	bool collision = false;
	Rectangle newHitbox = _hitbox;
	newHitbox.x = newPos.x;
	newHitbox.y = newPos.y + TEXTURE_SIZE / 2;

	vector<ObjFormat*> vec = returnVecLayer(*_ptr, ENEMY);
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