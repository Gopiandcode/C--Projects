#include "machine.h"
#include <iostream>

int main() {

	char c = '\n';
	SodaMachine machine =  SodaMachine(); 

	do {
		std::cout << "\nYour options are:\n\t[R]eturn all change\n\t[Q]uarter dispense into machine\n\t[D]ime dispense into machine\n\t[N]ickel dispense into machine\nOr you can try purchasing a drink:\n\t[C]ola can purchase\n\t[L]ite can purchase\n\t[B]eer(root) can purchase\n\t[O]range can purchase\n\t[F]ree can purcase\nor you can [e]xit\n";	
		std::cin >> c;
		if(c != 'e')
		machine.DoCommand(c);
	} while(c != 'e');

}
