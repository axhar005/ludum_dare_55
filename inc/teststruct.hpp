#pragma once

#include "ImageFormat.hpp"
#include "game.hpp"

struct testStruct : public ObjFormat{
	testStruct();
	~testStruct();
	void step() override;

	Texture2D cat;
	Texture2D cat2;
	vec_tex vec;
};
