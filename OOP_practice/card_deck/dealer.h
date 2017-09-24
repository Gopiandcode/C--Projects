#ifndef DEALER_H
#define DEALER_H

#include "player.h"

class Dealer{ 
	public:
		Dealer();
		void playGame();
		void determineResults();
	private:
		Player p;
		Deck d;

		Card hand[5];
		int numCards;

		int handValue(int);
		void showHand(int);

		void shuffle();
		void dealHand();

		void startHand();
		void dealACardToPlayer();
		void dealACardToDealer();
		void dealPlayerCards();
		void dealDealerCards();
		void findBestHand();
		int endOfDeck();
};
#endif //DEALER_H
