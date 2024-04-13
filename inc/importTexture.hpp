#pragma once

// #include <raylib.h>
#include "../lib/raylib/src/raylib.h"
#include <stdexcept>
#include <string.h>
#include <vector>
#include <iostream>

using std::vector;

Texture2D			importImageToTexture2D(const char *name);
vector<Texture2D>	ImportFileTexture(const char* const filesName[]);
