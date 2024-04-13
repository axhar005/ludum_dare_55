#pragma once

// #include <raylib.h>
#include "../lib/raylib/src/raylib.h"
#include <map>
#include <vector>
#include <unistd.h>

using std::map;
using std::vector;

#define LAYER_NUMBER 6

typedef struct s_ObjFormat
{
	Vector2		vec2;
	Texture2D	img;
	//
	// if you need to add data to the obj add here
	//
}	t_ObjFormat;

typedef map<int , vector<t_ObjFormat> > Layer;

void	InitMapLayer(Layer &map);
void	AddImageFormatToLayer(Layer& input, int y, t_ObjFormat& img);
