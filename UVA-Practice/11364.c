#include <iostream>

int main()
{
    int length, stores, minloc = 99, maxloc = 0, temp;
    std::cin >> length;
    for(int i = 0; i<length; i++) {
        minloc = 99;
        maxloc = 0;
        std::cin >> stores;
        for(int j = 0; j<stores; j++) {
            std::cin >> temp;
            minloc = (temp < minloc) ? temp : minloc;
            maxloc = (temp > maxloc) ? temp : maxloc;
        }
        std::cout << 2*(maxloc - minloc) << std::endl;
    }
    return 0;
}

