#include "../inc/ImageFormat.hpp"

void	InitMapLayer(Layer &map) {
	if (map.empty()) {
		for (int i = 0; i < LAYER_NUMBER; i++) {
			map.insert(std::make_pair(i, vector<t_ObjFormat>()));
		}
	}
}

void	AddImageFormatToLayer(Layer& input, int y, t_ObjFormat& img) {
	if (y < 0 || y > LAYER_NUMBER)
		return;
	input[y].push_back(img);
}

void	render(Layer& layer) {
	for (int i = 0; i < LAYER_NUMBER; i++) {
		for (size_t j = 0; j < layer[1].size(); j++) {
			t_ObjFormat& tmp = layer[i][j];
			DrawTexture(tmp.img, tmp.vec2.x, tmp.vec2.y, WHITE);
		}
	}
}