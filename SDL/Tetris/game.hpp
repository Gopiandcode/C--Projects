#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>

#include "Well.hpp"
#include "Tetronimo.hpp"

class Game {
	public:
		Game();
		~Game();
		bool tick();
	private:
		// private copy constructor
		Game(const Game &);
		Game &operator=(const Game &);


		SDL_Window *window_;
		SDL_Renderer *renderer_;
		Well well;
		Tetronimo tetronimo_;
		uint32_t moveTime_;
		

};

#endif
