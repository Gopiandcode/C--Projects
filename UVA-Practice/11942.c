#include <iostream>

int main()
{
    int N, x, xplusone;


    std::cin >> N;
    std::cout << "Lumberjacks:"<<std::endl;
    while(N > 0) {
        int a = 2;
        bool increasing = false, success = true;
        std::cin >> x;
        std::cin >> xplusone;
        while(x == xplusone) {
            std::cin >> xplusone;
            a++;
        }

        if(x < xplusone) increasing = true;

        x = xplusone;

        for(int i = 0; i<10-a; i++) {
            std::cin >> xplusone;
            if(xplusone == x) continue;
            if(x < xplusone) {
                    if(!increasing) success = false;
            }
            else {
                if(increasing) success = false;
            }
            x = xplusone;
        }

        if(success)std::cout << "Ordered" << std::endl;
        else std::cout <<"Unordered" << std::endl;
        N--;
    }

    return 0;
}


