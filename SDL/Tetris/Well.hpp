#ifndef WELL_HPP
#define WELL_HPP
#include <SDL2/SDL.h>

class Well {
	public:
		Well();
		void draw(SDL_Renderer *renderer);
		enum {Width = 10, Height=20};
	private:
		bool data[Width][Height];
};
#endif
