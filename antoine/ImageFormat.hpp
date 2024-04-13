#pragma once

#include <raylib.h>
#include <map>
#include <vector>

using std::map;
using std::vector;

#define LAYER_NUMBER 6

typedef struct s_ImageFormat
{
	Vector2		vec2;
	Texture2D	img;
}	t_ImageFormat;

typedef map<int , vector<t_ImageFormat> > Layer;