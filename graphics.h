#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer; // 2 forward declaring allows you to use variable names for pointers even though they haven't been included yet

class Graphics {
public:
	Graphics(); // 2 graphics constructor
	~Graphics(); // 2 graphics destructor

	// Loads an image into the _spriteSheets map if it doesnt already exist
	SDL_Surface* loadImage(const std::string &filePath);

	// Draws a texture to a certain part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	// Renders everything to the screen
	void flip();

	// Clears the screen
	void clear();

	// Returns the renderer
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window; // 2 where we are drawing
	SDL_Renderer* _renderer; // 2 does the drawing

	std::map <std::string, SDL_Surface*> _spriteSheets;
};

#endif
