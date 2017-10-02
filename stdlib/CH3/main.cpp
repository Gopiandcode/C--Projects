#include <iostream>
#include <cstddef>

void f(int x) {
	std::cout << "f(int) called with param " << x << " \n";
}

void f(void *x) {
	std::cout << "f(void*) called with param " << x << " \n";
}


void f(std::initializer_list<int> list) {
	for(auto &i : list) {
		std::cout << "f(initializer_list) called with " << i << "\n";
	}
}

class P {
	public:
	P(std::initializer_list<int> list) {
		for(auto &i : list) {
			std::cout << "P(initializer_list) called with " << i << "\n";
		}
	}
	P(int x) {
		std::cout << "P(int) called with " << x << "\n";
	}
};

int main() {
	std::cout << "Hello world!\n";
	// nullptr allows you to avoid NULL being interpreted as an integer
	// although it appears that results in a compilation failure in C++14 due to ambiguity
	f(0);
	f((int)NULL);
	f((void *)NULL);
	f(nullptr);


	// automatic type declarations
	auto x = 4;

	std::cout << "auto x = " << x << "\n";

	// initializer lists for uniform intialization
	f({1,2,3,4});

	P q(3);
	P a{3,4,4};
	P d{1};

	// the explicit keyword prevents initializer lists being automatically converted to versions supporting parameters
	P e = {1,2,3};
	
	// C++11 supports for in loops, use references to prevent unecassary assignments and copy operator calls
	for(auto &i : {1,2,3,4}) {
		std::cout << "Using an initializer list to print " << i << "\n";
	}
	// which is equivalent to the following
	std::initializer_list<int> i = {1,2,3,4};

	for(auto _pos = i.begin(), _end = i.end(); _pos != _end; ++_pos) {
		auto decl = *_pos;
		std::cout << "Using an equivalent for to print " << decl << "\n";
	}
	// and if the object doesn't support begin() and end(), calling global begin() and end() taking it as an argument

	for(auto _pos = begin(i), _end = end(i); _pos != _end; ++_pos) {
		auto decl = *_pos;
		std::cout << "Using an equivalent for with global end and begin to print " << decl << "\n";
	}

}
