#include <raylib.h>
#include "importTexture.hpp"

using std::vector;

#define t 800

int main(void) {
	InitWindow(800, 800, "test window");
	Texture2D	pic = importImageToTexture2D("cat.png");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(pic, t/2 - pic.width/2 , t/2 - pic.height/2 , WHITE);
		DrawFPS(0,0);
		EndDrawing();
	}
	UnloadTexture(pic);
	CloseWindow();
	return (0);
}