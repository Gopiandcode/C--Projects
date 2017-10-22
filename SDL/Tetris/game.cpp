#include <SDL2/SDL.h>
#include <iostream>
#include "game.hpp"

Game::Game() : tetronimo_(static_cast<Tetronimo::Type>(rand() % 7)), moveTime_(SDL_GetTicks()) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO)");
	}

	SDL_CreateWindowAndRenderer(720/2, 720, SDL_WINDOW_OPENGL, &window_, &renderer_);

}

Game::~Game() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();	
}


bool Game::tick() {
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
	SDL_RenderClear(renderer_);

	well.draw(renderer_);
	tetronimo_.draw(renderer_);

	if(SDL_GetTicks() > moveTime_) {

		moveTime_ += 1000;
		tetronimo_.move(0,1);
	}
	SDL_RenderPresent(renderer_);
	return true;
}
