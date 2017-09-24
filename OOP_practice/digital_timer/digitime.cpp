#include <iostream>
#include "digittime.hpp"


Display::Display(int lim) {
	value = 0;
	limit = lim;
}

void Display::Increment() {
	value++;
	if(value == limit)
		value = 0;
}

void Display::SetValue(int val) {
	if(val < 0)
		value = (-val % limit);
	value = (val % limit);
}


int Display::GetValue() {
	return value;
}


void Display::Show() {
	if(value < 10)
		std::cout <<'0';
	std::cout << value;
}


int Display::GetLimit() {
	return limit;
}


Timer::Timer() : hours(24), minutes(60) {}


void Timer::Increment() {
	minutes.Increment();
	if(minutes.GetValue() == 0)
		hours.Increment();
}

void Timer::Set() {
	int setting;

	std::cout << "Set hours to what value?\n";
	std::cout << "Enter an integer between 0 and " << hours.GetLimit() << ": ";
	std::cin >> setting;
	hours.SetValue(setting);


	std::cout << "Set hours to what value?\nEnter an integer between 0 and " << minutes.GetLimit() << ": ";
	std::cin >> setting;
	minutes.SetValue(setting);
}


void Timer::Show() {
	hours.Show();
	std::cout << ':';
	minutes.Show();
}
