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

int val(int **A, int i, int W, std::vector<int> items) {
    if(A[i][W] != -1) return A[i][W];

    if(i == 0) {
        if(items[i] <= W){
            A[i][W] = items[i];
        } else {
            A[i][W] = 0;
        }
        return A[i][W];
    }

    if(items[i] > W) {

        // Can't be added - move on to next item.
        return val(A, i-1, W, items);
    } else {
        int with = val(A, i-1, W-items[i], items) + items[i];
        int without = val(A, i-1, W, items);
        A[i][W] = max(with, without);
        return A[i][W];
    }
}


int main() {

    // Get the number of test cases.
    int n;
    std::cin >> n;

    for(int test_case = 0; test_case < n; ++test_case) {

        // Get the input.
        int m;
        std::cin >> m;
        std::vector<int> coins(0);
        int sum = 0;

        for(int i = 0; i<m; i++) {
            int inp;
            std::cin >> inp;
            coins.push_back(inp);
            sum += inp;
        }


        int **states = (int **) malloc(sizeof(int *) * (m));
        for(int i = 0; i<=m; i++) {
            states[i] = (int *) malloc(sizeof(int) * (sum + 1));
            for(int j = 0; j<=sum; j++) {
                states[i][j] = -1;
            }
        }

        int closest = val(states, m-1, sum / 2, coins);

        int result = sum - 2*closest;

        std::cout << result << std::endl;


    }

}

