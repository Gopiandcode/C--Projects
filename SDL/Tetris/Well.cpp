#include "Well.hpp"

Well::Well() : data{{false}} {
}


void Well::draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	for(auto x = 0; x < Width;  ++x){
		for(auto y = 0; y < Height; ++y) {
			if(data[x][y]) {
				SDL_Rect rect{x*720/2/10, y * 720/2/10 + 720/2/10, 720/2/10, 720/2/10 };
				SDL_RenderFillRect(renderer,&rect);
			}
			else {
				SDL_RenderDrawPoint(renderer, x * 720/2/10 + 720/2/10/2, y * 720/2/10 + 720/2/10/2);
			}
		}
	}
}


