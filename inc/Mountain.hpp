#pragma once
#include <cstddef>

class Mountain
{
private:
	char **_mountain;
	size_t _size;
public:
	// Constructors / Destructor
	Mountain(size_t const &size);
	~Mountain();

	void generateMountain();
	void printMountain() const;
	int sidePicker(int &result, unsigned int &x, unsigned int &y);
	void fillMountain();
	bool isBotAWall(size_t &x, size_t &y) const;
	bool isTopAWall(size_t &x, size_t &y) const;
	bool isLeftAWall(size_t &x, size_t &y) const;
	bool isRightAWall(size_t &x, size_t &y) const;
	char **getMountain() const;
	size_t getXStart() const;
	size_t getYStart() const;
};
