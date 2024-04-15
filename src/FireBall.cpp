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
		std::cout << _dir << std::endl;

		if (point_distance(_pos, getPLayer()->_pos) > 8 * TEXTURE_SIZE)
			kill();

	// this->_hitbox = {_pos.x, _pos.y + TEXTURE_SIZE / 2, TEXTURE_SIZE, TEXTURE_SIZE / 2};
	// Vector2 newPos = _pos;



	// //hitbox logic
	// bool moveplayer = true;
	// bool collision = false;
	// Rectangle newHitbox = _hitbox;
	// newHitbox.x = newPos.x;
	// newHitbox.y = newPos.y + TEXTURE_SIZE / 2;

	// vector<ObjFormat*> vec = returnVecLayer(*_ptr, ENEMY);
	// for (int i = 0; i < vec.size(); i++)
	// {
	// 	if (vec[i] == nullptr)
	// 		continue ;
	// 	collision = CheckCollisionRecs(newHitbox, vec[i]->_hitbox);
	// 	if (collision)
	// 	{
	// 		moveplayer = false;
	// 		break ;
	// 	}
	// }

	// if (moveplayer)
	// {
	// 	_pos = newPos;
	// }
}