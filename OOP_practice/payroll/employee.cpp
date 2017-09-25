#include "employee.h"

#include <iostream>
#include <string.h>

float Permanent::benefitDeduction = 100.00;

Employee::Employee() {
	std::cout << "\nType employee name:";
	std::cin.getline(name, 30);
	std::cout << "\nType employee address:";
	std::cin.getline(address, 80);
	std::cout << "\nType social security number:";
	std::cin.getline(socSecNumber, 10);
}

Employee::Employee(char *n, char *a, char *ssn) {
	strcpy(name, n);
	strcpy(address, a);
	strcpy(socSecNumber, ssn);
}

Temporary::Temporary() {
	std::cout << "\nType hours worked: ";
	std::cin >> hoursWorked;
	std::cout << "\nType hourly rate: ";
	std::cin >> hourlyRate;
}

Temporary::Temporary(char *n, char *a, char *ssn, float hw, float hr) : Employee(n, a, ssn), hoursWorked(hw), hourlyRate(hr) {}

void Temporary::PrintCheck() {
	netPay = hourlyRate * hoursWorked;
	std::cout << "\n\n______________________________________";
	std::cout << "\n\nPAY TO THE ORDER OF: " << '\t' << name;
	std::cout << "\n\t\t\t" << address;
	std::cout << "\n\t\t\t" << socSecNumber << '\n';
	std::cout << "\nEMPLOYEE CLASS: Temporary";
	std::cout << "\n\nHOURS: " << hoursWorked;
	std::cout << "\nRATE: " << hourlyRate;
	std::cout << "\n\nTHE AMOUNT OF *************$" << netPay <<'\n';
	std::cout << "\n\n_____________________________________\n\n";
}

Permanent::Permanent() {
}

Permanent::Permanent(char *n, char *a, char *ssn): Employee(n, a, ssn) {}


Hourly::Hourly() {
	std::cout << "\nType number of hours worked: ";
	std::cin >> hoursWorked;
	std::cout << "\nType hourly rate: ";
	std::cin >> hourlyRate;
}

Hourly::Hourly(char *n, char *a, char *ssn, float hw, float hr): Permanent(n, a, ssn), hoursWorked(hw), hourlyRate(hr) {}


void Hourly::PrintCheck() {
	netPay = hoursWorked * hourlyRate - benefitDeduction;
	std::cout << "\n\n______________________________________";
	std::cout << "\n\nPAY TO THE ORDER OF: " << '\t' << name;
	std::cout << "\n\t\t\t" << address;
	std::cout << "\n\t\t\t" << socSecNumber << '\n';
	std::cout << "\nEMPLOYEE CLASS: Hourly";
	std::cout << "\n\nBENEFITS DEDUCTION: " << benefitDeduction;
	std::cout << "\n\nHOURS: " << hoursWorked;
	std::cout << "\nRATE: " << hourlyRate;
	std::cout << "\n\nTHE AMOUNT OF *************$" << netPay <<'\n';
	std::cout << "\n\n_____________________________________\n\n";
}

Salaried::Salaried() {
	std::cout << "\nType weekly salary: ";
	std::cin >> weeklyPay;
}

Salaried::Salaried(char *n, char *a, char *ssn, float wp): Permanent(n, a, ssn), weeklyPay(wp) {}


void Salaried::PrintCheck() {
	netPay = weeklyPay - benefitDeduction;
	std::cout << "\n\n______________________________________";
	std::cout << "\n\nPAY TO THE ORDER OF: " << '\t' << name;
	std::cout << "\n\t\t\t" << address;
	std::cout << "\n\t\t\t" << socSecNumber << '\n';
	std::cout << "\nEMPLOYEE CLASS: salaried";
	std::cout << "\n\nBENEFITS DEDUCTION: " << benefitDeduction;
	std::cout << "\nSALARY: " << weeklyPay;
	std::cout << "\n\nTHE AMOUNT OF *************$" << netPay <<'\n';
	std::cout << "\n\n_____________________________________\n\n";

}
