#ifndef TETRONIMO_HPP
#define TETRONIMO_HPP
#include <SDL2/SDL.h>

class Tetronimo {
	public:
		enum Type {I=0, J, L, O, S, T, Z} type_;
		Tetronimo(Type);
		void draw(SDL_Renderer *renderer);
		void move(int dx, int dy);
		void rotate();
		bool isBlock(int x, int y) const;
		int x() const;
		int y() const;
	private:
		int x_;
		int y_;
		int angle_;

};
#endif
