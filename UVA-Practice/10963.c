#include <iostream>
#include <stdlib.h>
//area/numanims * envfriend *numanims
int main() {
    int cases;
    std::cin >> cases;
    while(cases>0) {
        int columns;
        std::cin >> columns;
        int flag = 1;
        int gap = 0;
        while(columns > 0) {
            int y1, y2;
            std::cin>>y1>>y2;
            if(gap == 0) gap = abs(y1-y2);
            else if(gap != abs(y1-y2) && flag) flag = 0;

        columns--;
        }
            if(flag) std::cout << "yes" << std::endl;
            else std::cout << "no" << std::endl;

        cases--;
        if(cases != 0) std::cout << std::endl;
    }
    return 0;
}

