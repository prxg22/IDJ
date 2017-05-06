#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>

#include "Tilemap.hpp"

class Resources
{
private:
	std::unordered_map<std::string, Resource*> resourceTable;
public:
	Resources();
	~Resources();
	SDL_Texture* getImage(const std::string& file);
	Tilemap* getTilemap(const std::string& file);
	void clear();
};

#endif