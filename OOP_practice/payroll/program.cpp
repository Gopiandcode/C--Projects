#include "employee.h"
#include <iostream>


int main() {
	Employee *employees[6];

	std::cout << "\n\nCreating a temporary employee pay record . . .";
	Temporary t((char *)"Clipper Decker", (char *)"Clinton, NY", (char *)"123456789", 40.0, 5.25);
	employees[0] = &t;

	std::cout << "\n\nCreating a hourly employee pay record . . .";
	Hourly h((char *)"Sparky Hirschfield", (char *)"Deansboro, NY", (char *)"234567890", 30.5, 8.50);
	employees[1] = &h;

	std::cout << "\n\nCreating a salaried employee pay record . . .";
	Salaried s((char *)"Fenton Sugarman", (char *)"Boston, MA", (char *)"2345678901", 500.00);
	employees[2] = &s;

	std::cout << "Enter data for a temporary employee pay record: . . .";
	employees[3] = new Temporary;


	std::cout << "Enter data for a hourly  employee pay record: . . .";
	employees[4] = new Hourly;

	std::cout << "Enter data for a salaried employee pay record: . . .";
	employees[5] = new Salaried;

	int i;
	for(i = 0; i < 6; ++i) {
		employees[i]->PrintCheck();
		std::cout << "\n\n\n";
	}

}
