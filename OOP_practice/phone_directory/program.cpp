#include "fonebook.h"

#include <iostream>

void ShowMenu() {
	std::cout << "\n\t\t*** Phone Directory ***";
	std::cout << "\n\tI \tInsert a new entry into the directory";
	std::cout << "\n\tL \tLook up an entry";
	std::cout << "\n\tR \tRemove an entry";
	std::cout << "\n\tU \tUpdate an entry";
	std::cout << "\n\tD \tDisplay the entire directory";
	std::cout << "\n\t? \tDisplay this menu";
	std::cout << "\n\tQ \tQuit";
}


char GetAChar(char *promptString) {
	char response;
	std::cout << promptString;
	std::cin >> response;
	response = toupper(response);
	// discard newline
	std::cin.get();
	return response;
}

char Legal(char c) {
	return ((c == 'I') || (c == 'L') || (c == 'R') || (c=='U') || (c == 'D') || (c=='?') || (c=='Q'));
}

char GetCommand() {
	char *prompt = (char *)"\n\n>";
	char cmd = GetAChar(prompt);
	while(!Legal(cmd)) {
		std::cout << "\nIllegal command, please try again ...";
		ShowMenu();
		cmd = GetAChar(prompt);
	}
	return cmd;
}

int main() {
	Directory d;
	ShowMenu();
	char command;

	do {
		command = GetCommand();
		switch(command) {
			case 'I': d.insert(); break;
			case 'L': d.lookup(); break;
			case 'R': d.remove(); break;
			case 'U': d.update(); break;
			case 'D': d.displayDirectory(); break;
			case '?': ShowMenu(); break;
			case 'Q': break;
		}
	} while(command != 'Q');
	return 0;
}
