#include "../inc/game.hpp"

testStruct::testStruct(Texture2D _tex): ObjFormat(_tex){
    
}

testStruct::~testStruct() {
    // Cleanup code here
}

void testStruct::step(){
    std::cout << "allo\n";
}