#include <iostream>
#include "digittime.hpp"

int main() {
	Timer t;
	std::cout << "Here's the initial value of the timer: ";
	t.Show();
	std::cout << "\n\n";
	t.Set();
	std::cout << "Here are the new settings: ";
	t.Show();
	std::cout << "\n";
	
	std::cout << "Now we will run it for 10 minutes .. .. ..\n";
	int i;
	for(i = 0; i < 10; ++i) {
		t.Increment();
		t.Show();
		std::cout << '\n';
	}	
	std::cout << "\nPress 'x' to exit the program...";
	char any;
	std::cin >> any;
	std::cout << "\nProcessing Completed...GOODBYE\n";


	return 0;
}
