#ifndef RIDER_H
#define RIDER_H
#include "elevate.h"
enum Status {WAITING,ABOARD,SERVED};

class Rider {
	public:
		Rider(int num, Elevator *e, int start = 1);
		void GetOn(Elevator *e);
		void GetOff(Elevator *e);
		void PushButton(Elevator *e, int thisfloor);

		void SelectFloor(Elevator *e);
		void Respond(Elevator *e);
		Status s;
	private:
		int startFloor;
		int destinationFloor;
		int number;
};
#endif // RIDER_H
