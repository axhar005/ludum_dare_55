#include "../inc/ImageFormat.hpp"
#include <iostream>

void	s_ObjFormat::kill(void) {
	rm = true;
}

void	InitMapLayer(Layer &map) {
	if (map.empty()) {
		for (int i = 0; i < LAYER_NUMBER; i++) {
			map.insert(std::make_pair(i, vector<t_ObjFormat>()));
		}
	}
}

t_ObjFormat	MakeObj(Texture2D img) {
	t_ObjFormat result;
	bzero(&result, sizeof(result));
	result.img = img;
	return (result);
}

void	AddImageFormatToLayer(Layer& input, int y, t_ObjFormat& img) {
	if (y < 0 || y > LAYER_NUMBER)
		return;
	img.rm = false;
	input[y].push_back(img);

}

void	render(Layer& layer) {
	for (int i = 0; i < LAYER_NUMBER; i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			t_ObjFormat& tmp = layer[i][j];
			if (layer[i][j].rm) {
				vector<t_ObjFormat>::iterator it = layer[i].begin() + j;
				layer[i].erase(it);
				j--;
				continue ;
			}
			DrawTexture(tmp.img, tmp.vec2.x, tmp.vec2.y, WHITE);
			tmp.step();
		}
	}
}

void	cleanLayer(Layer& layer) {
	for (size_t i = 0; i < layer.size(); i++) {
		for (size_t j = 0; j < layer[i].size(); j++) {
			UnloadTexture(layer[i][j].img);
		}
	}
}