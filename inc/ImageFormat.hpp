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

typedef vector<Texture2D> vec_tex;

struct ObjFormat
{
	public:
	// constructor / deconstructor
		ObjFormat(void);
		virtual 			~ObjFormat(void);
		virtual	void		step(void);
		void				kill(void);
		virtual Texture2D 	*animation(vec_tex &vec, double frameTime, bool reset = false);

	// variables
		Vector2				_pos;
		Rectangle			_hitbox;
		Texture2D			*_texture;
		bool				_rm;
	private:
	//
	// if you need to add data to the obj add here
	//
};

typedef map<int , vector<ObjFormat*> > Layer;


//*			//							//
vector<ObjFormat*>&		editTextureLayer(Layer& layer, int cal);
ObjFormat*				editTexture(Layer& layers, int cal, size_t pose);
void					editTextureLayerFt(vector<ObjFormat>& list, int(*ft)(ObjFormat&));


void					InitMapLayer(Layer &map);
void					AddImageFormatToLayer(Layer& input, int y, ObjFormat* img);
//void					cleanLayer(Layer& layer);
//*			//							//

void					render(Layer& layer);
