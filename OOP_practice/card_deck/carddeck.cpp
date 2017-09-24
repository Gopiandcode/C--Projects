#include "carddeck.h"

#include <iostream>
#include <string>

void Card::display() {
	int v = getVal();
	if((2 <= v) && (v <= 10))
		std::cout << v;
	else {
		char c = '\0';
		switch (v) {
			case 11: c = 'J'; break;
			case 12: c = 'Q'; break;
			case 13: c = 'K'; break;
			case 14: c='A'; break;
		}
		if(c != '\0')
			std::cout << c;
	}
	std::string s = std::string();
	switch(getSuit()) {
		case clubs: s = "clubs"; break;
		case diamonds: s = "diamonds"; break;
		case hearts: s = "hearts"; break;
		case spades: s = "spades"; break;
	}
	std::cout << " of " << s << '\n';
}


int Card::getVal() {
	return (val);
}

void Card::setVal(int v) {
	if(v <= 14 && v >= 2)
		val = v;
}

Suit Card::getSuit() {
	return (s);
}

void Card::setSuit(Suit st) {
	s = st;
}

Deck::Deck() {
	topCard = 0;
	int i;
	for(i = 0; i < 52; i++) {
		cards[i].setVal((i % 13) + 2);
		switch(i/13) {
			case 0: cards[i].setSuit(clubs); break;
			case 1: cards[i].setSuit(diamonds); break;
			case 2: cards[i].setSuit(hearts); break;
			case 3: cards[i].setSuit(spades); break;
		}
	}
}
