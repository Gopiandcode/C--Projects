#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stack>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define MAX_VALUE 300000

const int denominations[] = {1,5,10,25,50};
const int denomintions_count = 5;

int A[denomintions_count][MAX_VALUE];

int find_count(int type, int value) {

    if(value < 0 || type == denomintions_count) return 0;
    if(value == 0) return 1;

    if(A[type][value] != 0) return A[type][value];


    A[type][value] = find_count(type+1, value) + find_count(type, value-denominations[type]);

    return A[type][value];
}


int main() {
    int money;
    while(std::cin >> money) {
        int value = find_count(0, money);
        if(value > 1) std::cout << "There are " << value << " ways to produce " << money << " cents change." << std::endl;
        else std::cout << "There is only 1 way to produce " << money << " cents change." << std::endl;
    }
}

