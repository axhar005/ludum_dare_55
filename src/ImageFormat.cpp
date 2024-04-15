#include "../inc/ImageFormat.hpp"
#include "../inc/game.hpp"
#include <iostream>

ObjFormat::ObjFormat(void) {
	_rm = false;
	_texture = nullptr;
	_ptr = nullptr;
	bzero(&_pos, sizeof(_pos));
}

ObjFormat::ObjFormat(Layer* ptr) {
	_rm = false;
	_texture = nullptr;
	_ptr = ptr;
};

ObjFormat::~ObjFormat(void) {
	
}

void	ObjFormat::kill(void) {
	_rm = true;
}

void	ObjFormat::step(void) {
	//add stuff here
	//*	this->vec2.x += 5;
	//*	if (this->vec2.x >= 300)
	//*		this->kill();
}

Texture2D *ObjFormat::animation(vec_tex &vec, double frameTime, bool reset){
	static float timer = 0.0;
	static vec_tex::iterator it = vec.begin();
	if (reset)
		if (it == vec.end()) it = vec.begin();

	timer += GetFrameTime();
	if (timer >= frameTime) {
		timer = 0;
		it++;
		if (it == vec.end()) it = vec.begin();
	}
	return &(*it);
}

void	InitMapLayer(Layer &map) {
	if (map.empty()) {
		for (int i = 0; i < LAYER_NUMBER; i++) {
			map.insert(std::make_pair(i, vector<ObjFormat*>()));
		}
	}
}

void	AddImageFormatToLayer(Layer& input, int y, ObjFormat* img) {
	if (y < 0 || y > LAYER_NUMBER)
		return;
	img->_rm = false;
	input[y].push_back(img);
}

void	render(Layer& layer) {
	for (int i = 0; i < LAYER_NUMBER; i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			ObjFormat* tmp = layer[i][j];
			if (layer[i][j]->_rm) {
				vector<ObjFormat*>::iterator it = layer[i].begin() + j;
				delete tmp;
				layer[i].erase(it);
				j--;
				continue ;
			}
			Player *p = getPLayer();
			if (tmp->_texture){
				if (tmp->_pos.x >= p->_pos.x - (9*32) && tmp->_pos.x <= p->_pos.x + (9*32) && tmp->_pos.y >= p->_pos.y - (9*32) && tmp->_pos.y <= p->_pos.y + (9*32))	
					DrawTexture(*tmp->_texture, tmp->_pos.x, tmp->_pos.y, WHITE);
			}
			tmp->step();
		}
	}
}

void    ObjFormat::spawn(int layer, ObjFormat* obj) {
	if (_ptr && obj) {
		obj->_dir = 0;
		obj->_ptr = _ptr;
		obj->_rm = false;
		obj->_texture = NULL;
		AddImageFormatToLayer(*_ptr, layer, obj);
	}
}

void    ObjFormat::spawn(int layer, ObjFormat* obj, Vector2 pos) {
	if (_ptr && obj) {
		obj->_pos = pos;
		obj->_dir = 0;
		obj->_ptr = _ptr;
		obj->_rm = false;
		AddImageFormatToLayer(*_ptr, layer, obj);
	}
}


ObjFormat*	editObj(Layer& layers, int cal, size_t pose) {
	if (cal < 0 || cal > LAYER_NUMBER)
		return NULL;
	if (pose >= layers[cal].size())
		return NULL;
	return ((layers[cal][pose]));
}

/// @brief throw std::runtime_error
/// @param layer 
/// @param cal 
/// @return 
vector<ObjFormat*>&	returnVecLayer(Layer& layer, int cal) {
	if (cal < 0 || cal > LAYER_NUMBER)
		throw std::runtime_error("invalid index");
	return (layer[cal]);
}

/*
void	cleanLayer(Layer& layer) {
	for (size_t i = 0; i < layer.size(); i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			UnloadTexture(layer[i][j]->_texture);
		}
	}
}
*/

void	returnVecLayerFt(vector<ObjFormat>& list, int(*ft)(ObjFormat&)) {
	for (size_t i = 0; i < list.size() ; i++) {
		if (ft(list[i]))
			break ;
	}
}