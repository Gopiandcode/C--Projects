#include <iostream>
#include <string>
int main() {
    int cases, n, out;
    std::cin >> cases;
    while(cases != 0) {
        std::cin >> n;
        out = 315*n + 36962;
        out = (out<0) ? out*-1 : out;
        out /= 10;
        out %= 10;
        std::cout << out << std::endl;
        cases--;
    }

}

