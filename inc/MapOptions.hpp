#pragma once
#include <cstddef>

class MapOptions
{
private:
	size_t	_width;
	size_t	_height;
	unsigned int _numberOfMountains;
	size_t _sizeOfMountain;

public:
	// Constructors / Destructor
	MapOptions();
	MapOptions(size_t const &width, size_t const &height, size_t const &mountainSize, unsigned int const &mountainNb);
	~MapOptions();
	//functions
	size_t const &getWidth() const;
	size_t const &getHeight() const;
	unsigned int const &getNbOfMountain() const;
	size_t const &getSizeOfMountain() const;
};
