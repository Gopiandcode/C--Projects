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

class callable {
	int x,y;

	public:
	callable(int c) {
		x = c + 3;
		y = c / 2;
	}

	int operator() (int g) {
		return g * x * y;
	}

	int operator() (int p, int z) {
		return x * p * z * y;
	}
};

int main() {
	std::cout << "Hello world!\n";
	try {
		print_bitstring("010101010101000111001#");
	} catch(const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	callable caller(2);

	std::cout << caller(8) << ", " << caller(3, 2) << std::endl;
}
