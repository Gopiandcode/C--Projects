#ifndef CARDDECK_H
#define CARDDECK_H
enum Suit {clubs, diamonds, hearts, spades};

class Card {
	public:
		void display();
		int getVal();
		void setVal(int);
		Suit getSuit();
		void setSuit(Suit);

	private:
		Suit s;
		int val;
};

class Deck {
	friend class Dealer;
	public:
		Deck();
	private:
		int topCard;
		Card cards[52];
};

#endif //CARDDECK_H
