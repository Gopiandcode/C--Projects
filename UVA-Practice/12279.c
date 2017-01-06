#include <iostream>
#include <string>
int main() {
    int events, bal = 0, val, cases = 0;
    while(std::cin >> events, events != 0) {
        bal = 0;
        while(events > 0) {
            std::cin >> val;
            if(val>0) bal++;
            else bal--;
            events--;
        }
        cases++;
        std::cout<< "Case " << cases << ": "<< bal << std::endl;
    }
    return 0;
}


