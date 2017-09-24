#ifndef FONEBOOK_H
#define FONEBOOK_H
#include "entry.h"

class Directory {
	public:
		Directory();
		~Directory();
		void insert();
		void lookup();
		void remove();
		void update();
		void displayDirectory();
	private:
		int maxSize, currentSize;
		Entry *entryList;
		void grow();
		int findName(char *name);
};

#endif //FONEBOOK_H
