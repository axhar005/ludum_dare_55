#include "../inc/game.hpp"
#include "unistd.h"

/// @brief take file name
/// @param name path
/// @return new texture2D
Texture2D	importImageToTexture2D(const char *name) {
	Image	tmp;
	bzero(&tmp, sizeof(tmp));
	tmp = LoadImage(name);
	std::cout << name << std::endl;
	std::cout << getcwd(0, 0) << std::endl;
	if (!tmp.data)
		throw std::runtime_error("can't impore image");
	Texture2D result = LoadTextureFromImage(tmp);
	UnloadImage(tmp);
	return (result);
}

vector<Texture2D>	ImportFileTexture(std::string name, const char* const filesName[]) {
	vector<Texture2D>	result;
	if (!filesName)
		return (result);
	try {
		for (size_t i = 0; filesName[i]; i++) {
			result.push_back(importImageToTexture2D(filesName[i]));
		}
	}
	catch(const std::exception& e) {
		std::cout << "fail in ImportFileTexture:" << e.what() << std::endl;
	}
	return (result);
}


//  void ImageResize(Image *image, int newWidth, int newHeight); 
Texture2D	importImageToTexture2D(const char *name, int newWidth, int newHeight) {
	Image	tmp;
	bzero(&tmp, sizeof(tmp));
	tmp = LoadImage(name);
	std::cout << name << std::endl;
	std::cout << getcwd(0, 0) << std::endl;
	if (!tmp.data)
		throw std::runtime_error("can't impore image");

	ImageResize(&tmp, newWidth, newHeight);
	Texture2D result = LoadTextureFromImage(tmp);
	UnloadImage(tmp);
	return (result);
}