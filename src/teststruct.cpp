#include "../inc/game.hpp"


testStruct::testStruct(){
	cat = importImageToTexture2D("/Users/oboucher/project/ludum_dare_55/antoine/cat.png");
	cat2 = importImageToTexture2D("/Users/oboucher/project/ludum_dare_55/antoine/cat2.png");

	vec.push_back(cat);
	vec.push_back(cat2);
}

testStruct::~testStruct() {
	// Cleanup code here
}

void testStruct::step() {

	_texture = animation(vec, 1);
	//texture handle

	//logical handle
}
