#include "fraction.h"
#include <iostream>

Fraction operator+(Fraction f1, Fraction f2) {
	Fraction r;
	r.numerator = (f1.numerator * f2.denonminator) + (f2.numerator * f1.denonminator);
	r.denonminator = f1.denonminator * f2.denonminator;
	return r;
}

Fraction::Fraction(int n, int d) : numerator(n), denonminator(d) {}


Fraction::Fraction(): numerator(0), denonminator(1) {}


void Fraction::Get() {
	char divSign; // to consume /
	std::cin >> numerator >> divSign >> denonminator;
}

void Fraction::Show() {
	std::cout << numerator << '/' << denonminator;
}

double Fraction::Evaluate() {
	double n = numerator;
	double d = denonminator;
	return (n/d);
}
