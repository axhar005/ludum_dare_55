#include "../inc/Mountain.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>
#include <stdlib.h>

Mountain::Mountain(size_t const &size) : _size(size) {
	_mountain = (char **)calloc(size + 1, sizeof(char *));
	if (!_mountain)
		throw std::bad_alloc();
	for (size_t y = 0; y < size; y++) {
		_mountain[y] = (char*)calloc(size + 1, sizeof(char));
		if (!_mountain[y])
			throw std::bad_alloc();
		for (size_t x = 0; x < size; x++) {
			_mountain[y][x] = '0';
		}
	}
	generateMountain();
}

Mountain::~Mountain() {
}

int Mountain::sidePicker(int &result, unsigned int &x, unsigned int &y) {
	switch (result) {
		case 1:
			if (x + 1 < _size) {
				x++;
				return false;
			} else {
				return true;
			}
		case 2:
			if (x - 1 > 0) {
				x--;
				return false;
			} else {
				return true;
			}
		case 3:
			if (y + 1 < _size) {
				y++;
				return false;
			} else {
				return true;
			}
		case 4:
			if (y - 1 > 0) {
				y--;
				return false;
			} else {
				return true;
			};
	}
	return true;
}

void Mountain::generateMountain() {
	for (size_t j = 0; j < _size * 2; j++) {
		int result = 0;
		unsigned int x = _size / 2;
		unsigned int y = _size / 2;
		bool outOfBounce = false;
		for (size_t i = 0; i < _size * 2 && !outOfBounce; i++) {
			if (x > 0 || x < _size - 1 || y > 0 || y < _size - 1) {
				while (_mountain[y][x] == '1') {
					outOfBounce = sidePicker(result, x, y);
					if (outOfBounce) {
						break;
					}
				}
				if (!outOfBounce) {
					_mountain[y][x] = '1';
					srand(time(NULL) + rand());
					int tempResult = result;
					result = rand() % 4 + 1;
					int tmp;
					if (result == tempResult) {
						switch (result) {
							case 1:
								tmp = 2;
								break;
							case 2:
								tmp = 3;
								break;
							case 3:
								tmp = 4;
								break;
							case 4:
								tmp = 1;
								break;
						}
						sidePicker(tmp, x, y);
					} else {
						sidePicker(result, x, y);
					}
				}
			} else {
				break;
			}
		}
	}
	fillMountain();
}

bool Mountain::isTopAWall(size_t &x, size_t &y) const{
	unsigned tmpY = y - 1;
	return (tmpY >= 0  && tmpY < _size && _mountain[tmpY][x] == '1') ? 1 : 0;
}

bool Mountain::isBotAWall(size_t &x, size_t &y) const{
	unsigned tmpY = y + 1;
	return (tmpY >= 0  && tmpY < _size && _mountain[tmpY][x] == '1') ? 1 : 0;
}

bool Mountain::isLeftAWall(size_t &x, size_t &y) const{
	unsigned tmpX = x - 1;
	return (tmpX >= 0  && tmpX < _size && _mountain[y][tmpX] == '1') ? 1 : 0;
}

bool Mountain::isRightAWall(size_t &x, size_t &y) const{
	unsigned tmpX = x + 1;
	return (tmpX >= 0  && tmpX < _size && _mountain[y][tmpX] == '1') ? 1 : 0;
}
void Mountain::fillMountain() {
	for (size_t y = 0; y < _size; y++) {
		for (size_t x = 0; x < _size; x++) {
			int result = isTopAWall(x, y) + isBotAWall(x, y) + isRightAWall(x, y) + isLeftAWall(x, y);
			if (result >= 2)
				_mountain[y][x] = '1';
		}
	}
}

void Mountain::printMountain() const {
	for (size_t y = 0; y < _size; y++) {
		std::cout << _mountain[y] << std::endl;
	}
}

char **Mountain::getMountain() const {
	return _mountain;
}

size_t Mountain::getYStart() const {
	size_t y = 0;
	for (; y < _size; y++) {
		for (size_t x = 0; x < _size; x++) {
			if (_mountain[y][x] == '1')
				return y;
		}
	}
	return y;
}

size_t Mountain::getXStart() const {
	size_t x = 0;
	for (; x < _size; x++) {
		for (size_t y = 0; y < _size; y++) {
			if (_mountain[y][x] == '1')
				return x;
		}
	}
	return x;
}