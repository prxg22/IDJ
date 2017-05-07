#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <unordered_map>

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager
{
private:
	bool mouseState[6];
	int mouseUpdate[6];
	std::unordered_map<int, bool> keyState;
	std::unordered_map<int, int> keyUpdate;
	int _quitRequested;
	int updateCounter;
	int mouseX;
	int mouseY;
public:
	InputManager();
	~InputManager();
	
	void update();
	
	bool keyPress(int key);
	bool keyRelease(int key);
	bool isKeyDown(int key) const;
	
	bool mousePress(int button);
	bool mouseRelease(int button);
	bool isMouseDown(int button) const;
	
	int getMouseX() const;
	int getMouseY() const;
	
	bool quitRequested();
};

#endif