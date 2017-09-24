#include "dealer.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

void randomize() {
	unsigned int seed = unsigned(clock());
	srand(seed);
}

Dealer::Dealer() : numCards(0) { shuffle();}
void Dealer::playGame() {
	std::cout << "\n\nGame on!!\n\n";
	do {
		dealHand();
		findBestHand();
	} while(!endOfDeck());
}

void Dealer::determineResults() {
	std::cout << "\n\nPLAYER #1 started with a pot of 10\n";
	std::cout << "*** FINAL POT: " << p.pot << '\n';
}

int Dealer::handValue(int startCard) {
	int v;
	int total = 0;
	for(int i = startCard; i < numCards; ++i) {
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
void Dealer::showHand(int startCard) {
	std::cout << "\nDealer's hand: \n";
	int i;
	for(i = startCard; i < numCards; ++i) {
		hand[i].display();
	}
	std::cout << "*** Value showing: " << handValue(startCard) << '\n';
}
void Dealer::shuffle() {
	randomize();
	int i, j;
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 52; ++j) {
			int r = rand() % 52;
			Card c = d.cards[j];
			d.cards[j] = d.cards[r];
			d.cards[r] = c;
		}
	}
}
void Dealer::dealHand() {
	startHand();
	dealPlayerCards();
	dealDealerCards();
}
void Dealer::startHand() {
	p.numCards = 0;
	numCards = 0;
	dealACardToPlayer();
	dealACardToDealer();
	dealACardToPlayer();
	dealACardToDealer();
	p.showHand();
	showHand(1);
}

void Dealer::dealACardToPlayer() {
	p.hand[p.numCards++] = d.cards[d.topCard++];
}
void Dealer::dealACardToDealer() {
	hand[numCards++] = d.cards[d.topCard++];
}
void Dealer::dealPlayerCards() {
	char ans;
	do {
		std::cout << "\nDo you want another card?";
		std::cout << "(Y for yes, N for no)?\n";
		std::cin >> ans;
		ans = toupper(ans);
		if(ans == 'Y'){
			dealACardToPlayer();
			p.showHand();
		}
	} while((ans == 'Y') && (p.handValue() < 21) && (p.numCards <= 5));
}
void Dealer::dealDealerCards() {
	showHand(0);
	while((handValue(0) < 17) && (numCards <= 5)) {
		dealACardToDealer();
		showHand(0);
	}
}
void Dealer::findBestHand() {
	int pVal = p.handValue();
	int dVal = handValue(0);

	if(((pVal > 21) && (dVal > 21)) || (pVal ==  dVal)){
		std::cout << "hand was a draw\n";
	} else if(((pVal <= 21) && (pVal > dVal)) || (dVal > 21)) {

		std::cout << "Player #1 wins hand\n";
		p.pot++;
	} else if(((dVal <= 21) && (dVal > pVal)) || (
				pVal > 21)){
		std::cout << "Computer wins hand\n";
		p.pot--;
	}
}

inline int Dealer::endOfDeck() {
	return (d.topCard >= 42);
}
