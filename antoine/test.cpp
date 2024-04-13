#include <raylib.h>
#include "importTexture.hpp"
#include "ImageFormat.hpp"

using std::vector;

#define t 800

const char *const  a[] = {"cat.png"};

int main(void) {
	InitWindow(800, 800, "test window");

	//Texture2D	pic = importImageToTexture2D("cat.png");
	vector<Texture2D> test = ImportFileTexture(a);
	
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(test[0], t/2 - test[0].width/2 , t/2 - test[0].height/2 , WHITE);
		DrawFPS(0,0);
		EndDrawing();
	}
	UnloadTexture(test[0]);
	CloseWindow();
	return (0);
}