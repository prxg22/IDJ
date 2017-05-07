#include "Tileset.hpp"

#include <cstdio>

Tileset::Tileset(int columns, int rows, const std::string& file) : 
columns(columns), rows(rows), tileset(file){
	if (!tileset.isOpen()) {
		fprintf(stderr, "Tileset isn't open\n");
		return;
	}
	tileWidth = tileset.getWidth()/columns;
	tileHeight = tileset.getHeight()/rows;
}

void Tileset::render(unsigned index, float x, float y){
	if (index >= columns*rows) {
		return;
	}
	int i = index / columns;
	int j = index % columns;
	tileset.setClip(j * tileWidth, i * tileHeight, tileWidth, tileHeight);
	tileset.render(x, y);
}

int Tileset::getTileWidth() const {
	return tileHeight;
}
int Tileset::getTileHeight() const {
	return tileHeight;
}
