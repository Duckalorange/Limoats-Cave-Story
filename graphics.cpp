// Graphics Class
// Episode 2

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"


Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer); // 2 creates the window
	SDL_SetWindowTitle(this->_window, "Cavestory"); // 2 sets window title
}

Graphics::~Graphics(){ // 2 graphics destructor
	SDL_DestroyWindow(this->_window); // 2 closes window
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if (this->_spriteSheets.count(filePath) == 0) { // has not been loaded
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath]; // only load each image once
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}
