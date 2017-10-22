#include "Tetronimo.hpp"
#include <iostream>

Tetronimo::Tetronimo(Type type): type_(type),x_(10/2-4/2), y_(0), angle_(0) {}


void Tetronimo::draw(SDL_Renderer *renderer) {
	std::cout << "Drawing!" << std::endl;
	switch(type_) {
		case I:
			SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
			break;
		case J:
			SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, 0xff);
			break;
		case L:
			SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0xff, 0xff);
			break;
		case O:
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x7f, 0xff);
			break;
		case S:
			SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
			break;
		case T:
			SDL_SetRenderDrawColor(renderer, 0x7f, 0x40, 0x00, 0xff);
			break;
		case Z:
			SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);
			break;
	}
	std::cout << "Colour set!" << std::endl;
	static const char *Shapes[] = {
		" *  "
		" *  "
		" *  "
		" *  ",

		"    "
		"****"
		"    "
		"    ",

		" *  "
		" *  "
		" *  "
		" *  ",

		"    "
		"****"
		"    "
		"    ",




		" *  "
		" *  "
		" *  "
		"**  ",

		"*   "
		"****"
		"    "
		"    ",

		" ** "
		" *  "
		" *  "
		" *  ",

		"    "
		"****"
		"   *"
		"    ",




		"    "
		" ** "
		" ** "
		"    ",
		"    "
		" ** "
		" ** "
		"    ",
		"    "
		" ** "
		" ** "
		"    ",
		"    "
		" ** "
		" ** "
		"    ",




		"  * "
		" ** "
		" *  "
		"    ",

		"**  "
		" ** "
		"    "
		"    ",

		" *  "
		" ** "
		"  * "
		"    ",

		"**  "
		" ** "
		"    "
		"    ",




		" *  "
		" ** "
		" *  "
		"    ",

		"    "
		"*** "
		" *  "
		"    ",

		" *  "
		"**  "
		" *  "
		"    ",

		" *  "
		"*** "
		"    "
		"    ",




		" *  "
		" ** "
		"  * "
		"    ",
		
		" ** "
		"**  "
		"    "
		"    ",
		
		" *  "
		" ** "
		"  * "
		"    ",

		" ** "
		"**  "
		"    "
		"    "
	};



	for(auto x = 0; x < 4; ++x) {
		for(auto y = 0; y < 4; ++y){
	std::cout << "iterating(" << x << ", " << y <<")" << std::endl;
	std::cout << "Checking [" << type_ * 4 + angle_  << "][" << x + y * 4 <<"]" << std::endl;
		if(Shapes[type_ * 4 + angle_][x + y * 4] != ' ') 	{
	SDL_Rect rect{(x + x_)* 720/2/10, (y+y_)*720/2/10/2,720/2/10, 720/2/10};
	SDL_RenderFillRect(renderer, &rect);
		} 
		}
	}

}

void Tetronimo::move(int dx, int dy) {
	x_ += dx;
	y_ += dy;

}


void Tetronimo::rotate() {
	++angle_;
	angle_ %= 4;
}
