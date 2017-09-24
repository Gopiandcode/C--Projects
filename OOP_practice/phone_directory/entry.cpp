#include "entry.h"
#include <string.h>

std::istream& operator >> (std::istream& s, Entry& e) {
	std::cout << "\nType name, followed by RETURN or ENTER: ";
	s.getline(e.name, 20);
	std::cout << "\nType phone number, followed by RETURN or ENTER: ";
	s.getline(e.phoneNumber, 20);

	std::cout << "Type room number followed by RETURN or ENTER: ";
	s.getline(e.address, 20);

	return s;
}

std::ostream& operator << (std::ostream& s, const Entry& e) {
	int i;

	s << '\t' << e.name;
	for(i = strlen(e.name) + 1; i < 20; ++i) s.put(' ');

	s << '\t' << e.phoneNumber;
	for(i = strlen(e.phoneNumber) + 1; i < 20; i++) s.put(' ');
	s << '\t' << e.address;
	s << '\n';

	return s;
}


Entry::Entry() {
	strcpy(name, " ");
	strcpy(phoneNumber, " ");
	strcpy(address, " ");
}

char *Entry::getName() {
	return name;
}
