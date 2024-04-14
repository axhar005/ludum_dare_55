#pragma once
#include "MapOptions.hpp"
#include "Mountain.hpp"
#include <cstddef>
#include <vector>


class Map
{
private:
	Map();
	char **_map;
	MapOptions const _mapOptions;

public:
	// Constructors / Destructor
	Map(MapOptions const &mapOptions);
	~Map();

	// Functions
	void baseMapGenerator();
	void printMap() const;
	void mountainGenerator();
	void copyMountainOnMap(size_t &x, size_t &y, Mountain mountain);
	void protectCenter();
};
