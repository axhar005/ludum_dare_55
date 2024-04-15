#include "../inc/Map.hpp"
#include "../inc/Mountain.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <new>

Map::Map(MapOptions const &mapOptions) : _mapOptions(mapOptions) {
	_map = (char **)calloc(mapOptions.getHeight() + 1, sizeof(char *));
	if (!_map) {
		throw std::bad_alloc();
	}
	baseMapGenerator();
	mountainGenerator();
	protectCenter();
	// //printMap();
}

Map::~Map() {
}

void Map::baseMapGenerator() {
	for (size_t y = 0; y < _mapOptions.getHeight(); y++) {
		_map[y] = (char *)calloc(_mapOptions.getWidth() + 1, sizeof(char));
		for (size_t x = 0; x < _mapOptions.getWidth(); x++) {
			if (y == 0 || x == 0 || x == _mapOptions.getWidth() - 1 || y == _mapOptions.getHeight() - 1)
				_map[y][x] = '1';
			else
				_map[y][x] = '0';
		}
	}
}

void Map::copyMountainOnMap(size_t &x, size_t &y, Mountain mountain) {
	char **mountainMap = mountain.getMountain();

	size_t mY = mountain.getYStart();
	for (size_t i = y; i < _mapOptions.getHeight() && mY < _mapOptions.getSizeOfMountain(); i++) {
		size_t mX = mountain.getXStart();
		for (size_t j = x; j < _mapOptions.getWidth() && mX < _mapOptions.getSizeOfMountain(); j++) {
			if (_map[i][j] == '0' && mountainMap[mY][mX] == '1')
				_map[i][j] = '1';
			mX++;
		}
		mY++;
	}
}

void Map::mountainGenerator() {
	for (unsigned int i = 0; i < _mapOptions.getNbOfMountain(); i++) {
		srand(time(NULL) + rand());
		size_t x = rand() % _mapOptions.getWidth() + 1;
		size_t y = rand() % _mapOptions.getHeight() + 1;
		size_t centerX = _mapOptions.getWidth() / 2;
		size_t centerY = _mapOptions.getHeight() / 2;
		while ((centerX < x || centerX > x + _mapOptions.getSizeOfMountain()) && (centerY < y || centerY > y + _mapOptions.getSizeOfMountain())) {
			srand(time(NULL) + rand());
			x = rand() % _mapOptions.getWidth() + 1;
			y = rand() % _mapOptions.getHeight() + 1;
		}
		Mountain mountain(_mapOptions.getSizeOfMountain());
		copyMountainOnMap(x, y, mountain);
	}
}

void Map::printMap() const {
	for (size_t y = 0; y < _mapOptions.getHeight(); y++) {
		std::cout << _map[y] << std::endl;
	}
}

void Map::protectCenter() {
	size_t centerX = (_mapOptions.getWidth() / 2) - 3;
	size_t centerY = (_mapOptions.getHeight() / 2) - 3;

	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			_map[centerY + y][centerX + x] = '0';
		}
	}
	_map[_mapOptions.getHeight() / 2][_mapOptions.getWidth() / 2] = 'X';
}

char **Map::getMap() const{
	return _map;
}