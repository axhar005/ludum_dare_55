#include "game.hpp"

struct testStruct : public ObjFormat{
    testStruct(Texture2D _tex);
    ~testStruct();
    void step() const override;
};