#pragma once

#include "game.hpp"

struct testStruct : public ObjFormat{
	testStruct();
	~testStruct();
	void step() override;

	Texture2D cat;
};
