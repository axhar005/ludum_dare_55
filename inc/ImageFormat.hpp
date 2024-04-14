#pragma once

// #include <raylib.h>
#include "../lib/raylib/src/raylib.h"
#include <map>
#include <vector>
#include <unistd.h>
#include <string.h>

using std::map;
using std::vector;

#define LAYER_NUMBER 6

typedef struct s_ObjFormat
{

	Vector2		vec2;
	Texture2D	img;
	void	kill(void);
	bool	rm;
	virtual void step(void);
	//
	// if you need to add data to the obj add here
	//
}	t_ObjFormat;

typedef map<int , vector<t_ObjFormat> > Layer;


t_ObjFormat	MakeObj(Texture2D img);

//*			//							//

void		InitMapLayer(Layer &map);
void		AddImageFormatToLayer(Layer& input, int y, t_ObjFormat& img);

//*			//							//

void		render(Layer& layer);

