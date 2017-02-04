#include <iostream>



int main()
{
    int T, N, maximum,a, current = 1;

    std::cin >> T;
    while(current <= T) {
        std::cin>>N;
        std::cin >> maximum;
        for(int i = 1; i<N; i++) {std::cin >> a;if(a > maximum) maximum = a;}

        std::cout << "Case " << current << ": " << maximum << std::endl;
        current++;
    }




    return 0;
}


