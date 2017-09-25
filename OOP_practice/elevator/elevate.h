#ifndef ELEVATE_H
#define ELEVATE_H

const int FLOORSINBLDG = 10;
enum Direction {DOWN, UP};
enum Button {OFF, ON};


class Elevator {
	public:
		Elevator();
		int ButtonsPushed();
		void MoveToNextFloor();
		Button floorButtons[FLOORSINBLDG + 1];
		int currentFloor;
		Direction going;
		void DisplayStatus();
	private:
		int ChooseMove();
};
#endif //ELEVATE_H
