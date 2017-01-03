#include <iostream>

int main()
{
    int length, a,b;
    std::cin >> length;
    for(int i = 0; i<length; i++) {
        std::cin >> a >> b;
        std::cout << ((a/3) * (b/3)) << std::endl;
    }
    return 0;
}

