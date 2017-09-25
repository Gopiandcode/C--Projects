#include "rider.h"
#include <iostream>

Rider::Rider(int num, Elevator *e, int start): s(WAITING),startFloor(start),number(num) {
	PushButton(e,startFloor);
	std::cout << "\n\nPassenger " << number << " is waiting at floor " << startFloor << '\n';
}

void Rider::Respond(Elevator *e) {
	if((s == WAITING) && (e->currentFloor == startFloor)) {
		GetOn(e);
		return;
	}
	if((s == ABOARD) && (e->currentFloor == destinationFloor)) {
		GetOff(e);
		return;
	}
}

void Rider::GetOn(Elevator *e) {
	s = ABOARD;
	std::cout << "\nPassenger " << number << " enters elevator at floor " << e->currentFloor << '\n';
	SelectFloor(e);
}

void Rider::GetOff(Elevator *e) {
	s = SERVED;
	std::cout << "\nPassenger " << number << " leaves elevator at floor " << e->currentFloor << '\n';
}

void Rider::PushButton(Elevator *e, int thisfloor) {
	e->floorButtons[thisfloor] = ON;
}

void Rider::SelectFloor(Elevator *e) {
	std::cout << "\nTravelling to which floor (1-" << FLOORSINBLDG << ") ?";
	std::cin >> destinationFloor;
	PushButton(e, destinationFloor);
}
