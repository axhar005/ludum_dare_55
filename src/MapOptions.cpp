#include "../inc/MapOptions.hpp"
#include <cstddef>
#include <iostream>

MapOptions::MapOptions() : _width(0), _height(0) {
	std::cout << "Initializing an empty  MapOptions class!" << std::endl;
}

MapOptions::MapOptions(size_t const &width, size_t const &height, size_t const &mountainSize, unsigned int const &mountainNb) :  _width(width), _height(height), _numberOfMountains(mountainNb), _sizeOfMountain(mountainSize) {
}

MapOptions::~MapOptions() {
}

size_t const &MapOptions::getWidth() const {
	return _width;
}

size_t const &MapOptions::getHeight() const {
	return _height;
}

unsigned int const &MapOptions::getNbOfMountain() const {
	return _numberOfMountains;
}

size_t const &MapOptions::getSizeOfMountain() const {
	return _sizeOfMountain;
}