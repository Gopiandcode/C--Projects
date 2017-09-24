#include "fonebook.h"
#include "string.h"

Directory::Directory(): maxSize(5), currentSize(0) {entryList = new Entry[maxSize];}


Directory::~Directory(){delete[] entryList;}


void Directory::insert() {
	if(currentSize == maxSize) {
		grow();
	}
	std::cin >> entryList[currentSize++];
}


void Directory::lookup() {
	char aName[20];
	std::cout << "\tType the name to be looked up followed by ENTER: ";
	std::cin.getline(aName, 20);

	int thisEntry = findName(aName);

	if(thisEntry == -1)
		std::cout << aName << " not found in the current directory\n";

	else {
		std::cout << "\nEntry found: ";
		std::cout << entryList[thisEntry];
	}
}

void Directory::remove() {
	char aName[20];
	std::cout << "\tType the name to be removed followed by ENTER: ";
	std::cin.getline(aName, 20);

	int thisEntry = findName(aName);
	if(thisEntry == -1)
		std::cout << aName << " not found in the directory";
	else {
		int j;
		for(j = thisEntry + 1; j < currentSize; j++) {
			entryList[j - 1] = entryList[j];
		}
		currentSize--;
		std::cout << "Entry removed.\n";
	}
}

void Directory::update() {
	char aName[20];
	std::cout << "\nPlease enter the name of the directory entry to be modified: ";
	std::cin.getline(aName, 20);	
	int thisEntry = findName(aName);

	if(thisEntry == -1) 
		std::cout << aName << " was not found in the current Directory\n";
	else {
		std::cout << "\nCurrent entry is: \n";
		std::cout << entryList[thisEntry];
		std::cout << "\nReplace with new entry as follows: \n";
		std::cin >> entryList[thisEntry];
	}
}

void Directory::displayDirectory() {
	if(currentSize == 0) {
		std::cout << "\nCurrent directory is empty\n";
		return;
	} else {
		std::cout << "\n\t***NAME***\t\t***PHONE***\t\t***ADDRESS***\n\n";
		int i;
		for(i = 0; i < currentSize; ++i) {
			std::cout << entryList[i];
		} 
	}
}


void Directory::grow() {
	int newSize = 2 * currentSize;
	Entry *newlist = new Entry[newSize];

	for(int i = 0; i < currentSize; i++) {
		newlist[i] = entryList[i];
	}
	delete[] entryList;
	entryList = newlist;

	maxSize = newSize;
}

int Directory::findName(char *aName) {
	int i;
	for(i = 0; i < currentSize; i++) {
		if(strcmp(entryList[i].getName(), aName) == 0)
			return i;
	}
	return -1;
}


