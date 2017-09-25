#include "user.h"

#include <iostream>
#include <string>

User::User() {
	ShowMenu();
}

char User::GetCommand() {
	char cmd;
	while(1) {

		std::cout << "\n> ";
		std::cin >>cmd;
	        cmd = toupper(cmd);

		if(IsLegal(cmd)) {
			if(cmd == 'M')
				ShowMenu();
			else
				return cmd;
		} else {
			std::cout << "\n*** Unrecognized command.";
			std::cout << " Type M to see menu.";
		}
	}
}

int User::IsLegal(char cmd) {
	return ((cmd == 'Q') || (cmd == 'D') || (cmd == 'R') || (cmd == 'C') || (cmd == 'L') || (cmd == 'B') || (cmd == 'O') || (cmd == 'F') || (cmd == 'X') || (cmd == 'M'));
}


void User::ShowMenu() {
	std::cout << "Please select one of the following options:\n";
	std::cout << "Money-handling\n\tQ: Quarter\n\tD: Dime\n\tN: Nickel\n\tR: Return all Coins\nDrink selection($0.75 each)\n\tC: Cola\n\tL: Lite Cola\n\tB: Root Beer\n\tO: Orange\n\tF: Caffeine-Free cola\nSimulation Control\n\tM: Show this menu\n\tX: Exit the program\n";
}
