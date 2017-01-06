#include <iostream>
#include <string>
int main() {
    using std::string;

    string command;
    string report = "report";
    int reports;
    long long int account = 0, val;
    std::cin >> reports;
    while(reports>0) {
        std::cin>>command;
        if(command == report) std::cout << account << std::endl;
        else {
            std::cin >> val;
            account += val;
        }



        reports--;
    }
    return 0;
}

