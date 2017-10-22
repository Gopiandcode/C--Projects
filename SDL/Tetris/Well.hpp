#ifndef WELL_HPP
#define WELL_HPP
#include <SDL2/SDL.h>
#include "Tetronimo.hpp"

class Well {
	public:
		Well();
		void draw(SDL_Renderer *renderer);
		enum {Width = 10, Height=20};
		bool isCollision(const Tetronimo&) const;
		void unite(const Tetronimo&);
	private:
		bool data[Width][Height];
};
#endif
