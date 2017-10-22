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

	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		switch(e.type) {
		case SDL_KEYDOWN:
			{
				switch(e.key.keysym.sym) {
		case SDLK_DOWN:
			{
				Tetronimo t = tetronimo_;
				t.move(0,1);
				check(t);
			}
			break;
		case SDLK_RIGHT:
			{
				Tetronimo t = tetronimo_;
				t.move(1,0);
				check(t);
			}
			break;
		case SDLK_LEFT:
			{
				Tetronimo t = tetronimo_;
				t.move(-1,0);
				check(t);
			}
			break;
		case SDLK_UP:
			{
				Tetronimo t = tetronimo_;
				t.rotate();
				check(t);
			}
			break;



				}
			}
			break;
		case SDL_QUIT:
			return false;

		}	
	}
	
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
	SDL_RenderClear(renderer_);

	well_.draw(renderer_);
	tetronimo_.draw(renderer_);

	if(SDL_GetTicks() > moveTime_) {

			moveTime_ += 1000;
			Tetronimo t = tetronimo_;
			t.move(0,1);
			check(t);
	}


	SDL_RenderPresent(renderer_);
	return true;
}


void Game::check(const Tetronimo& t) {
			// check for colission
			if(well_.isCollision(t)) {
				well_.unite(tetronimo_);
				tetronimo_ = Tetronimo(static_cast<Tetronimo::Type>(rand() % 7));


						if(well_.isCollision(tetronimo_)) {

						well_ = Well();
			}
		}
		 else {
			tetronimo_ = t;
		}

}
