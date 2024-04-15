#include "../inc/game.hpp"

float point_distance(Vector2 v1, Vector2 v2) {
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;

	return std::sqrt(dx * dx + dy * dy);
}

float point_direction(Vector2 point1, Vector2 point2) {
	float dx = point2.x - point1.x;
	float dy = point2.y - point1.y;
	
	float angleRadians = std::atan2(dy, dx);
	
	float angleDegrees = angleRadians * (180.0f / M_PI);
	
	if (angleDegrees < 0) {
		angleDegrees += 360.0f;
	}

	return angleDegrees;
}

void move_in_direction(Vector2& pos, float speed, float direction) {
	float angleRadians = direction * (M_PI / 180.0f);
	pos.x += speed * cos(angleRadians);
	pos.y += speed * sin(angleRadians);
}