#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>

#include "Tileset.hpp"
#include "Resource.hpp"

class Tilemap : public Resource
{
private:
	std::vector<int> tileMatrix;
	Tileset* tileset;
	int width;
	int height;
	int depth;
public:
	Tilemap(const std::string& path);
	~Tilemap();
	inline int& at(int x, int y, int z = 0) {
		return tileMatrix[z * width * height + y * width + x];
	}
	void render(int cameraX = 0, int cameraY = 0);
	void renderLayer(int layer, int cameraX = 0, int cameraY = 0);
	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
};

#endif