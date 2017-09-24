#ifndef PLAYER_H
#define PLAYER_H
#include "carddeck.h"

class Player {
	friend class Dealer;
	public:
		Player();
	private:
		Card hand[5];
		int pot;
		int numCards;
		int handValue();
		void showHand();
};
#endif //PLAYER_H
