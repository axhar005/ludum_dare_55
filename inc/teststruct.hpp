#include "game.hpp"

struct testStruct : public ObjFormat{
    testStruct();
    testStruct(Texture2D* _tex);
    ~testStruct();
    void step() override;
};