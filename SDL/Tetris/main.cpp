#include <SDL2/SDL.h>
#include "game.hpp"
#include <iostream>

int main() {
	std::cout << "Making the game!" << std::endl;
	Game game;
	std::cout << "Made the game!" << std::endl;
	while(game.tick()) {
		std::cout << "running" << std::endl;	
	};

}
