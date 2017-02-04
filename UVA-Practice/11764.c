#include <iostream>



int main()
{

    int T, N, x,xplusone,current = 1;
    std::cin >> T;
    while(current <= T) {
        std::cin >> N;
        int high,low = (high = 0);
        std::cin >> x;
        for(int i = 1; i<N; i++) {
                std::cin >> xplusone;
                if(x > xplusone) low++;
                else if( x < xplusone) high++;
                x = xplusone;
        }
        std::cout << "Case " << current << ": " << high << " " << low << std::endl;
        current++;
    }

    return 0;
}


