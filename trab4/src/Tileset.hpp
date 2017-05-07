#ifndef TILESET_HPP
#define TILESET_HPP

#include "Sprite.hpp"

class Tileset
{
private:
	Sprite tileset;
	int rows;
	int columns;
	int tileWidth;
	int tileHeight;
public:
	Tileset(int columns, int rows, const std::string& file);
	void render(unsigned index, float x, float y);
	int getTileWidth() const;
	int getTileHeight() const;
};

#endif