#include "../inc/ImageFormat.hpp"
#include <iostream>

ObjFormat::ObjFormat(void) {
	_rm = false;
	bzero(&vec2, sizeof(vec2));
}

ObjFormat::ObjFormat(Texture2D _tex): tex(_tex) {
	_rm = false;
	bzero(&vec2, sizeof(vec2));
}


ObjFormat::~ObjFormat(void) {
	
}

void	ObjFormat::kill(void) {
	_rm = true;
}

void	ObjFormat::step(void) const{
	//add stuff here
	//*	this->vec2.x += 5;
	//*	if (this->vec2.x >= 300)
	//*		this->kill();
    std::cout << "test\n";

}

void	InitMapLayer(Layer &map) {
	if (map.empty()) {
		for (int i = 0; i < LAYER_NUMBER; i++) {
			map.insert(std::make_pair(i, vector<ObjFormat>()));
		}
	}
}

ObjFormat	MakeObj(Texture2D tex) {
	ObjFormat result;
	// bzero(&result, sizeof(result));
	result.tex = tex;
	return (result);
}

void	AddImageFormatToLayer(Layer& input, int y, ObjFormat& img) {
	if (y < 0 || y > LAYER_NUMBER)
		return;
	img._rm = false;
	input[y].push_back(img);
}

void	render(Layer& layer) {
	for (int i = 0; i < LAYER_NUMBER; i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			ObjFormat& tmp = layer[i][j];
			if (layer[i][j]._rm) {
				vector<ObjFormat>::iterator it = layer[i].begin() + j;
				layer[i].erase(it);
				j--;
				continue ;
			}
			DrawTexture(tmp.tex, tmp.vec2.x, tmp.vec2.y, WHITE);
			tmp.step();
		}
	}
}

ObjFormat*	editTexture(Layer& layers, int cal, size_t pose) {
	if (cal < 0 || cal > LAYER_NUMBER)
		return NULL;
	if (pose > layers[cal].size())
		return NULL;
	return (&layers[cal][pose]);
}

/// @brief throw std::runtime_error
/// @param layer 
/// @param cal 
/// @return 
vector<ObjFormat>&	editTextureLayer(Layer& layer, int cal) {
	if (cal < 0 || cal > LAYER_NUMBER)
		throw std::runtime_error("invalid index");
	return (layer[cal]);
}

void	cleanLayer(Layer& layer) {
	for (size_t i = 0; i < layer.size(); i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			UnloadTexture(layer[i][j]->tex);
		}
	}
}

void	editTextureLayerFt(vector<ObjFormat>& list, int(*ft)(ObjFormat&)) {
	for (size_t i = 0; i < list.size() ; i++) {
		if (ft(list[i]))
			break ;
	}
}