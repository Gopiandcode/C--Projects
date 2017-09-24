#ifndef MACHINE_H
#define MACHINE_H

class CoinCounter {
	public:
		CoinCounter(int initial = 100);         // CoinCounter
		int CurrentAmount();                    // returns the amount tendered
		void AcceptCoin(int amt);               // Handle coin insertion
		void TakeAll();                         // Accept all coins in response to a sale
		void DispenseChange(int amt);           // if possible return all coins
	private:
		int amount;
		int available;
};

class Dispenser {
	public:
		Dispenser(int num = 24);                // Dispenser
		int HandleButton();                     // Handle button press
	private:
		int numCans;                            // number of available cans
};

class SodaMachine {
	public:
		SodaMachine();                          // SodaMachine
		void DoCommand(char cmd);               // Respond to a command from a user
	private:
		CoinCounter counter;                    // delegate all coin handling to a coin counter
		Dispenser cola,                         // various can dispensers
			  lite,
			  root,
			  orange,
			  free;
		int price;                              // all cans have the same price
		void DoCoin(char cmd);                  // handle a coin event
		void DoSelection(char cmd);             // handle a button press
};
#endif //MACHINE_H
