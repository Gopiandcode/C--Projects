#include <iostream>
#include <exception>
#include <string>
using std::string;

void print_bitstring(string s) {
	for(char c : s) {
		if(c != '0' && c != '1') {
			throw std::invalid_argument(string(&c,1) + " is not 0 or 1");
		}
	}

	std::cout << s << std::endl;
}

int main() {
	std::cout << "Hello world!\n";
	try {
		print_bitstring("010101010101000111001#");
	} catch(const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}
}
