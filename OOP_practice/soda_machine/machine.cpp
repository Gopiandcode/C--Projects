#include "machine.h"
#include <iostream>


CoinCounter::CoinCounter(int initial): amount(0), available(initial) {}
int CoinCounter::CurrentAmount() {
	return amount;
}
void CoinCounter::AcceptCoin(int amt) {
	amount += amt;
}
void CoinCounter::TakeAll() {
	available += amount;
	amount = 0;
}
void CoinCounter::DispenseChange(int amt) {
	if(available >= amt) {
		std::cout << "\n*** Change returned: " << amt;
		available -= amt;
	} else
		std::cout << "\n*** Exact Change Only from now on";
}

Dispenser::Dispenser(int num): numCans(num) {}
int Dispenser::HandleButton() {
	if(numCans == 0) {
		std::cout << "\n**** MAKE ANOTHER SELECTION for this from now on";
		return 0;
	}
	else {
		numCans--;
		std::cout << "\n***Sale complete";
		return 1;
	}
}

SodaMachine::SodaMachine(): price(75) {}
void SodaMachine::DoCommand(char cmd) {
	if((cmd == 'Q') || (cmd == 'D') || (cmd == 'N') || (cmd == 'R')) 
		DoCoin(cmd);
	else
		DoSelection(cmd);
}
void SodaMachine::DoCoin(char cmd) {
	int amt;
	switch(cmd) {
		case 'R':
			amt = counter.CurrentAmount();
			counter.TakeAll();
			counter.DispenseChange(amt);
			break;
		case 'Q': counter.AcceptCoin(25); break;
		case 'D': counter.AcceptCoin(10); break;
		case 'N': counter.AcceptCoin(5);  break;
	}
}

void SodaMachine::DoSelection(char cmd) {
	int tendered = counter.CurrentAmount();
	int success = 0;
	if(tendered < price)
		std::cout << "\n*** Insert more money";
	else {
		Dispenser *dispenser = NULL;
		switch (cmd) {
			case 'C': dispenser = &cola; break;
			case 'L': dispenser = &lite; break;
			case 'B': dispenser = &root; break;
			case 'O': dispenser = &orange; break;
			case 'F': dispenser = &free; break;
		}
		if(dispenser != NULL)
			success = dispenser->HandleButton();
		if(success) {
			counter.TakeAll();
			if(tendered > price)
				counter.DispenseChange(tendered - price);
		}
	}
}

