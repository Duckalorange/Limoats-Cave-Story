// Game class
// Episode 3

#include <SDL.h>
#include <algorithm>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace { // 3 used to limit frame rate
	const int FPS = 50; // 3 
	const int MAX_FRAME_TIME = 5 * 1000 / FPS; // 3 maximum time frame is allowed to last
}
Game::Game() { // 3 game constructor
	SDL_Init(SDL_INIT_EVERYTHING); // 3 initializes timer, audio, video, joystick, haptic, gamecontroller, events
	this->gameloop(); // 3 call gameloop from constructor
}

Game::~Game() { // 3 game constructor

}

void Game::gameloop() { // 3 important function
	Graphics graphics; // 3 create graphics object
	Input input;  // creates input object
	SDL_Event event; // 3 event object holds whatever event happens during that frame

	this->_player = Sprite(graphics, "Resource Files\\Content\\Spritesheet\\MyChar.png", 0, 0, 16, 16, 100, 100); // 4 Grabs sprite starting at top left corner puts on screen
	int LAST_UPDATE_TIME = SDL_GetTicks(); // 3 gets # of milliseconds since the SDL library was initialized

	// Start the game loop
	while (true){ // 3
		input.beginNewFrame(); //reset pressed keys and released keys

		if (SDL_PollEvent(&event)){ // 3 SDL will find out what events happen and put them in event variable
			if (event.type == SDL_KEYDOWN){ // 3 tells event key was pressed
				if (event.key.repeat == 0) { // 3 makes sure youre not holding down a key
					input.keyDownEvent(event); // 3 if not holding key pass keyDown event event
				}
			}
			else if (event.type == SDL_KEYUP) { // 3 key was released
				input.keyUpEvent(event); //
			}
			else if (event.type == SDL_QUIT) { // 3 Quit happens when you close the program or click the x
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) { // 3 closes if you hit escape
			return;
		}

		// limits frame rate
		const int CURRENT_TIME_MS = SDL_GetTicks(); // 3 current time now has however long while loop took
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME; // 3 compare current time and last update time and store in elapsed time
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME)); // 3 if elapsed time is less than max time use that, if not use max time
		LAST_UPDATE_TIME = CURRENT_TIME_MS; // 3 resets last update time
	}
}

void Game::draw(Graphics &graphics) { // 3
	graphics.clear();

	this->_player.draw(graphics, 100, 100);

	graphics.flip();
}

void Game::update(float elapsedtime) { // 3

}
