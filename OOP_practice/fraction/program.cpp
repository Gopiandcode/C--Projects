#include "fraction.h"
#include <iostream>


int main() {
	Fraction f1(3,2), f2(4), f3;
	std::cout << "\nThe fraction f1 is ";
	f1.Show();
	std::cout << "\nThe fraction f2 is ";
	f2.Show();
	std::cout << "\nThe fraction f3 is ";
	f3.Show();
	std::cout << "\nNow enter your own fraction: ";
	f3.Get();
	std::cout << "\nYou entered: ";
	f3.Show();

	Fraction f4 = f1 + f3;
	std::cout << "\n\nThe sum of ";
	f1.Show();
	std::cout << " and ";
	f3.Show();
	std::cout << " is ";
	f4.Show();

	std::cout << "The value of this fraction is " << f4.Evaluate() << "\n";

}
