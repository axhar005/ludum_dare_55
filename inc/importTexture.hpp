#pragma once

#include "../inc/game.hpp"

using std::vector;

Texture2D			importImageToTexture2D(const char *name);
Texture2D			importImageToTexture2D(const char *name, int newWidth, int newHeight);
vec_tex				ImportFileTexture(const char* const filesName[]);
