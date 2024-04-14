#include "../inc/game.hpp"


testStruct::testStruct(){
	cat = importImageToTexture2D("antoine/cat.png");
	cat2 = importImageToTexture2D("antoine/cat2.png");

	vec.push_back(cat);
	vec.push_back(cat2);
}

testStruct::~testStruct() {
	// Cleanup code here
}

void testStruct::step() {
	_texture = animation(gettexture("chat"), 0.5);
	//texture handle

	//logical handle
}
