#include <iostream>
#include <string>
int main() {
    using std::string;
    string s;
    int n = 0;
    while(std::cin >>s, s!= "#") {

        std::cout << "Case " << ++n << ": ";

        if(s == "HELLO")
            std::cout<<"ENGLISH" <<std::endl;

        else if(s == "HOLA")
            std::cout<<"SPANISH" << std::endl;

        else if( s == "HALLO")
            std::cout<<"GERMAN" << std::endl;

        else if(s == "BONJOUR")
            std::cout<<"FRENCH"<<std::endl;
        else if(s == "CIAO")
            std::cout<<"ITALIAN"<<std::endl;
        else if(s == "ZDRAVSTVUJTE")
            std::cout<<"RUSSIAN"<<std::endl;
        else
            std::cout<<"UNKNOWN"<<std::endl;

        }
    }


