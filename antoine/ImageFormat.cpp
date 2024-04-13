#include "ImageFormat.hpp"

void	InitMapLayer(Layer &map) {
	if (map.empty()) {
		for (int i = 0; i < LAYER_NUMBER; i++) {
			map.insert( std::make_pair(i, vector<t_ImageFormat>()));
		}
	}
}

void	AddImageFormatToLayer(Layer& input, int y, t_ImageFormat& img) {
	if (y < 0 || y > LAYER_NUMBER)
		return;
	input[y].push_back(img);
}