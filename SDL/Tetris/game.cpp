#include <SDL2/SDL.h>
#include <iostream>
#include "game.hpp"

Game::Game() {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO)");
	}

	SDL_CreateWindowAndRenderer(720/2, 720, 0, &window_, &renderer_);

}

Game::~Game() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();	
}


bool Game::tick() {
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);

	Tetronimo I(Tetronimo::I);
	I.draw(renderer_);
	Tetronimo J(Tetronimo::J);
	J.move(0,4);
	J.draw(renderer_);
	Tetronimo L(Tetronimo::L);
	L.move(0,8);
	L.draw(renderer_);
	Tetronimo O(Tetronimo::O);
	O.move(0,12);
	O.draw(renderer_);
	Tetronimo S(Tetronimo::S);
	S.move(0,16);
	S.draw(renderer_);
	Tetronimo T(Tetronimo::T);
	T.move(4,16);
	T.draw(renderer_);
	Tetronimo Z(Tetronimo::Z);
	Z.move(-4,16);
	Z.draw(renderer_);


	well.draw(renderer_);

	SDL_Delay(200000);
	return true;
}
