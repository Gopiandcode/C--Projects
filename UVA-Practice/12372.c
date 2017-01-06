#include <iostream>

int main() {
    int cases, l,w,h, current = 0;;
    std::cin >> cases;
    while(cases>0) {
        current++;
        std::cin >> l >> w >> h;
        if(l > 20 || w > 20 || h > 20) std::cout << "Case " << current << ": " << "bad" << std::endl;
        else std::cout << "Case " << current << ": " << "good" << std::endl;


        cases--;
    }
    return 0;
}

