#ifndef GAME_H
#define GAME_H

#include "sprite.h"

class Graphics; // 3 forward declare graphics

class Game{ // 3 game class
public:
	Game(); // 3 game constuctor
	~Game(); // 3 game destructor
private:
	void gameloop(); // 3 game loop
	void draw(Graphics &graphics); // 3 draw function passing a reference to graphics class
	void update(float elapsedTime); // 3 

	Sprite _player;
};
#endif
