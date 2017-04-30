#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>

#include <SDL2/SDL.h>

class Sprite {
	private:
		SDL_Texture* texture;
		int w, h;
		SDL_Rect clipRect;
	public:
		Sprite();
		Sprite(const std::string& file_name);
		~Sprite();
		void open(const std::string& file_name);
		void setClip(int x, int y, int w, int h);
		void close();
		void render(int x, int y);
};


#endif