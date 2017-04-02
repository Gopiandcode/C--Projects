#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdio>
int main()
{
    using std::vector;
    using std::array;
    int N;

    std::cin >> N;
    // Basic Input Gathering
    while(N > 0) {
        int M, C;
        std::cin >> M >> C;
        int initial_M = ++M;
        vector<vector<int>> items = vector<vector<int>>();
        for(int i = 0; i<C; i++){
            vector<int> v = vector<int>();
            int k;
            std::cin >> k;
            while(k > 0) {
                int item;
                std::cin >> item;
                v.push_back(item);
                k--;
            }
            items.push_back(v);
        }


        // Some dynamic programming - initialize the array to 0.
        bool bottom_up_dynamic_table[C][M];
        for(int i = 0; i<C; i++) {
            for(int j = 0; j<M; j++) bottom_up_dynamic_table[i][j] = 0;
        }
        for(int i = 0; i<C; i++) {
            // Go through each type of item, one at a time.
            vector<int> v = items[i];
            int mini = -1;
            for(int m : v) {
                // For each model of type of item, check the price.
                if(mini == -1 || m < mini) mini = m;
                if(i != 0) {
                    for(int j = 0; j<M; j++){
                        // Check the previous row to find entries which have true values.
                        if(bottom_up_dynamic_table[i-1][j]) {
                            // If we can purchase a model of this cost using the money, subtract it.
                            if(j - m > 0)
                                bottom_up_dynamic_table[i][j-m] = 1;
                        }
                    }
                }
                // For the first run, don't check the previous row, just subtract each value from the budget.
                else {
                    if(M-m > 0) bottom_up_dynamic_table[0][M-m] = 1;
                }
            }
            // Optimization to reduce the number of searches per row.
            M -= mini-1;
        }
        int found = -1;
        for(int i = 0; i<initial_M; i++) {
            if(bottom_up_dynamic_table[C-1][i] == 1) {
                found = i;
                break;
            }
        }

        if(found == -1)
            std::cout << "no solution" << std::endl;
        else{
            std::cout << (initial_M-found) << std::endl;;
        }




        N--;
    }


}


