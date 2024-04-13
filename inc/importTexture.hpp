#pragma once

#include "../inc/game.hpp"

using std::vector;

Texture2D			importImageToTexture2D(const char *name);
vector<Texture2D>	ImportFileTexture(const char* const filesName[]);
