#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stack>
#define MAX_VALUE 300000
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))


const int denominations[] = {200, 100, 50, 20, 10, 5};
const int denominations_count = 6;

int A[denominations_count][MAX_VALUE];

int find_counts(int type, int moneys) {

    if(moneys < 0) return 0;


    if(type == denominations_count) return 0;



    if(A[type][moneys] != -1) return A[type][moneys];


    int a = find_counts(type+1, moneys) + find_counts(type, moneys-denominations[type]);
    return A[type][moneys] = a;

}

int main() {
    for(int i = 0; i<denominations_count; i++) {
        for(int j = 0; j<MAX_VALUE; j++) {
            if(j == 0) A[i][j] = 1;
            else A[i][j] = -1;
        }
    }
    double input;


    while(std::cin >> input) {
        if(input == 0) break;
        int values = find_counts(0,(int)(input*100));
        std::printf("%6.2lf %17d\n", input, values);
    }

}

