#include "input.h"


// this function is called at the beginning of each new frame to reset keys no longer relevant
void Input::beginNewFrame() { 
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//This gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;  //sets the map to true
	this->_heldKeys[event.key.keysym.scancode] = true; //key is technically held when pressed so this is true too
}

//This gets called when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
	this-> _releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

//Check if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//Check if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//Check if a certain key is held
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}
