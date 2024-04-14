#include "../inc/game.hpp"


testStruct::testStruct(){
    
}

testStruct::testStruct(Texture2D* _tex): ObjFormat(_tex){
    
}

testStruct::~testStruct() {
    // Cleanup code here
}

void testStruct::step() {
    vec2.x += 2;
	if (this->vec2.x >= 300)
		this->kill();
}