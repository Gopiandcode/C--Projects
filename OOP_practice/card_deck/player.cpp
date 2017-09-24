#include "player.h"

#include <iostream>

Player::Player() : pot(10), numCards(0) {}

int Player::handValue() {
	int v;
	int total = 0;
	int i;
	for(i = 0; i < numCards; ++i) {
		v = hand[i].getVal();
		if(v <= 10)
			total += v;
		else if(v <= 13)
			total += 10;
		else
			total += 11;
	}
	return (total);
}

void Player::showHand() {
	std::cout << "\nPlayer #1's hand: \n";

	int i;
	for(i = 0;  i < numCards; ++i) {
		hand[i].display();
	}

	std::cout << "*** Total Value: " << handValue() << '\n';
}
