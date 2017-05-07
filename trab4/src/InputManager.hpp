#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <unordered_map>

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
	
	bool keyPress(int key) const;
	bool keyRelease(int key) const;
	bool isKeyDown(int key) const;
	
	bool mousePress(int button) const;
	bool mouseRelease(int button) const;
	bool isMouseDown(int button) const;
	
	int getMouseX() const;
	int getMouseY() const;
	
	bool quitRequested() const;
};

#endif