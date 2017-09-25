#include "elevate.h"

#include <iostream>

Elevator::Elevator() : currentFloor(1), going(UP) {
	int i;
	for(i = 0; i < FLOORSINBLDG + 1; ++i) {
		floorButtons[i] = OFF;
	}
}



int Elevator::ButtonsPushed() {
	int i;
	for(i = 0; i < FLOORSINBLDG + 1; ++i){ 
		if(floorButtons[i] == ON) return 1;
	}
	return 0;
}

int Elevator::ChooseMove() {
	int t;
	int i;
	for(t = 1; t <= 2; ++t) {
		if(going == UP) {
			// find any upward floor with button pressed
			for(i = currentFloor; i < FLOORSINBLDG + 1; ++i)
				if(floorButtons[i] == ON) return i;
			// else go down
			going = DOWN;
			continue;
		} else {
			for(i = currentFloor; i >= 0; --i){ 
				if(floorButtons[i] == ON) return i;
				going = UP;
				continue;
			}
			
		}
	}
	return -1;
}

void Elevator::MoveToNextFloor() {
	int newFloor = ChooseMove();
	if(newFloor == -1) {
		std::cout << "Elevator stopped at floor " << currentFloor;
	} else {
		currentFloor = newFloor;
		floorButtons[currentFloor] = OFF;
		DisplayStatus();
	}
}


void Elevator::DisplayStatus() {
	std::cout << "\nElevator is currently stopped at floor " << currentFloor << " heading ";
	if(going == UP) 
		std::cout << "up\n";
	else
		std::cout << "down\n";
}
