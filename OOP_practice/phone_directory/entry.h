#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
class Entry {
	friend std::istream& operator >> (std::istream&a, Entry& e);
	friend std::ostream& operator << (std::ostream&a, const Entry& e);

	public:
		Entry();
		char *getName();
	private:
		char name[20];
		char phoneNumber[20];
		char address[20];
};
#endif //ENTRY_H
