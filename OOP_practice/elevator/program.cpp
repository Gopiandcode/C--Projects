#include "elevate.h"
#include "rider.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	Elevator e;
	int s = int(clock());
	srand(s);

	int aFloor;

	aFloor = ((rand() % FLOORSINBLDG) + 1);
	Rider r1(1,&e, aFloor);

	aFloor = ((rand() % FLOORSINBLDG) + 1);
	Rider r2(2,&e, aFloor);

	aFloor = ((rand() % FLOORSINBLDG) + 1);
	Rider r3(3,&e, aFloor);

	aFloor = ((rand() % FLOORSINBLDG) + 1);
	Rider r4(4,&e, aFloor);
	while(e.ButtonsPushed()) {
		e.MoveToNextFloor();
		r1.Respond(&e);
		r2.Respond(&e);
		r3.Respond(&e);
		r4.Respond(&e);
	}

	std::cout << "\nRider 1 status: " << (int) r1.s;
	std::cout << "\nRider 2 status: " << (int) r2.s;
	std::cout << "\nRider 3 status: " << (int) r3.s;
	std::cout << "\nRider 4 status: " << (int) r4.s;

	std::cout << "\nElevator returned to ground floor having";
	std::cout << "\nprocessed all requests for service.";
}
