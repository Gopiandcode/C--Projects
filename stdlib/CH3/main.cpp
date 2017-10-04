#include <iostream>
#include <vector>
#include <cstddef>
#include <string>

constexpr int const_sqr(int x) {
	return x*x;
}
float const_defined_arr[const_sqr(23)];

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


void print() {}

template<typename T, typename... Types>
void print(const T&firstArg, const Types&... args) {
	std::cout << firstArg << std::endl;
	print(args...);
}


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



	// new string literals
	
	// old format
	std::string s = "\\\\n";
	// new format
	std::string k = R"(\\n)";

	std::cout << "old_format: " << s << ", new_format: " << k << "\n";

	// custom delimiters supported as well
	std::string p = R"cool(\n)cool";
	std::cout << p << "\n";

	print("Amazing", 1, "Cool, it's essentially python" , 3, "those noobs couldn't handle this stuff.");


	// lambdas!!!!
	[] {
		std::cout << "I'm in a lambda!" << std::endl;
	}();

	std::cout << [] (int a) -> int { return a +3; } (5);

	int id = 43;

	std::cout << "Id is initially " << id << std::endl;
	auto f = [id] () mutable { std::cout << "Inside the lambda id is " << id++ << std::endl;};
	f();
	f();
	f();
	f();
	std::cout << "Id is now " << id << std::endl;
	// std::function allows for defining the types of lambda with std::functioN<int(int,int)>
}

