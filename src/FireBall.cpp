#include "../inc/game.hpp"

FireBall::FireBall(void) {
	_speed = 4;
}

FireBall::~FireBall(void) {
	
}

void FireBall::step(void)
{
	//movement
		move_in_direction(_pos, _speed, _dir);

		if (point_distance(_pos, getPlayer()->_pos) > 8 * TEXTURE_SIZE)
			kill();

	this->_hitbox = {_pos.x + 8, _pos.y + 8, 8, 8};



	//hitbox logic
	bool collision = false;

	vector<ObjFormat*> vec = returnVecLayer(*_ptr, ENEMY);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr)
			continue ;
		collision = CheckCollisionRecs(_hitbox, vec[i]->_hitbox);
		if (collision)
		{
			vec[i]->kill();
			kill();
			break ;
		}
	}
}