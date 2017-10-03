#include <iostream>
#include <vector>
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

class X {
	friend std::ostream& operator<<(std::ostream& out, X &in) {
		out << "X(" << in.x << ");\n";
		return out;
	}
	private:
		int x;
	public:
	X(int _x) {
		x = _x;
	}
	X(const X& other) {
		x = other.x;
	}
	// add a move constructor
	X(X&& rvalue) {
		this->x = rvalue.x;
		rvalue.x = 0;
	}


	int operator++(){
		return x++;
	}

	X operator+ (const X &other) {
		return X(x + other.x);
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


	// also supports arrays of known size
	int array[] = { 1, 2, 3, 4, 5 };

	for(auto &i : array) {
		std::cout << i << "\n";
	}


	X xathon(3), yathon(2);


	std::cout << xathon << yathon;

	X cathon = xathon + yathon;

	std::cout << cathon;
	// exploring std::move
	//
	std::vector<X> item;

	// copy of x
	item.push_back(xathon);

	for(auto &i : item) {
		std::cout << i;
	}

	// let's try mutating xathon and then try printing the list
	++xathon;

	std::cout << "Xathon is now " << xathon;

	std::cout << "what's the one in the list like ? \n";
	for(auto &i : item) {
		std::cout << i;
	}
	// now try std::move
	
	item.push_back(std::move(xathon));


	// really by this point all the data in X has been moved out.
	++xathon;

	std::cout << "Xathon is now " << xathon;

	
	std::cout << "what's the one in the list like ? \n";
	for(auto &i : item) {
		std::cout << i;
	}




}
