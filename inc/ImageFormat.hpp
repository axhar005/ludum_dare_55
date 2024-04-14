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

struct ObjFormat
{
	public:
						ObjFormat(void);
						ObjFormat(Texture2D _tex);
		virtual 		~ObjFormat(void);
		virtual	void	step(void) const;
		Vector2			vec2;
		Texture2D		tex;
		void			kill(void);
		bool			_rm;
	private:
	//
	// if you need to add data to the obj add here
	//
};

typedef map<int , vector<ObjFormat*> > Layer;


ObjFormat				MakeObj(Texture2D img);

//*			//							//
vector<ObjFormat>&		editTextureLayer(Layer& layer, int cal);
ObjFormat*				editTexture(Layer& layers, int cal, size_t pose);
void					editTextureLayerFt(vector<ObjFormat>& list, int(*ft)(ObjFormat&));


void					InitMapLayer(Layer &map);
void					AddImageFormatToLayer(Layer& input, int y, ObjFormat* img);
void					cleanLayer(Layer& layer);
//*			//							//

void					render(Layer& layer);
