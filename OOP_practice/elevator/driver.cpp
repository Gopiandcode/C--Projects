#include "elevate.h"

#include <iostream>


int main() {
	Elevator e;
	e.DisplayStatus();

	e.floorButtons[4] = ON;
	e.floorButtons[7] = ON;
	e.MoveToNextFloor();
	e.floorButtons[2] = ON;
	e.MoveToNextFloor();
	e.MoveToNextFloor();
	std::cout << "\nWe made it!\n";
}

