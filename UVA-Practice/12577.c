#include <iostream>
#include <string>
int main() {
    using std::string;
    string command;
    int cases = 0;
    while(std::cin>>command, command != "*") {
        cases++;
        if(command == "Hajj") std::cout << "Case " << cases << ": Hajj-e-Akbar" << std::endl;
        else std::cout << "Case " << cases << ": Hajj-e-Asghar"<<std::endl;
    }


    return 0;
}


