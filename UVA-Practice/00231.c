#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    // Counter to represent which test the loop is on.
    int test_case = 1;

    while(1) {
        // Initialize Variables used in each loop.
        int i;
        int result = 1;
        std::vector<int> sequence = std::vector<int>();
        std::vector<int> costs = std::vector<int>();

        // Pre retrieve the first value input.
        std::cin >> i;


        // Checking for the terminating condition.
        if(i == -1) break;

        if(test_case != 1) {
            std::cout  << std::endl;
        }



        // Get the sequence of values.
        sequence.push_back(i);

        // Also initialize costs array.
        costs.push_back(1);


        int ci = 1,ck = 0;
        while(i != -1) {

            // Get input
            std::cin >> i;

            if(i!= -1) {

                sequence.push_back(i);
                int max = 0;

                costs.push_back(max);

                // Loop through all previous entries till
                // one with higher height is found
                for(ck = ci; ck>=0; ck--) {
                    if(sequence[ck] >= sequence[ci]) {
                        if(costs[ck] >= max) max = costs[ck];
                    }
                }

                // Update cost to be the maximum
                if(max+1 >= result) result = max+1;
                costs[ci] = max+1;
            }
            ci++;
        }



        // Print the output
        std::cout << "Test #" << test_case++ << ":" << std::endl;
        std::cout << "  maximum possible interceptions: " << result << std::endl;


    }
}

