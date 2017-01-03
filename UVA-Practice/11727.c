#include <iostream>
#include <algorithm>
int main() {
    int cases, val;
    int people[3];
    std::cin >> cases;
    for (int i = 1; i<= cases; i++) {
        for(int i = 0; i<3; i++) std::cin >> val, people[i] = val;
        std::sort(people, people+3);
        std::cout <<"Case " << i <<": " << people[1] << std::endl;
    }
}

