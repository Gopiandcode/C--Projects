#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>

/**
 * @brief Given a value and a correct ordering, gives the relative ordering for the value
 * @param value the Value for which the correct ordering must be found.
 * @param correct_ordering A ordering containing all the values.
 * @return the correct relative ordering.
 */
int getCorrect(int value, std::vector<int> correct_ordering) {
    int i;
    for(i = 0; i<correct_ordering.size(); i++) {
        if(value == correct_ordering[i]) return i;
    }
}


int main() {
    std::string line;
    int n;
    std::getline(std::cin, line);
    std::istringstream inp;


    while(1) {
        // End condition
        if(line.empty()) break;
        // Get input, continue.

        inp = std::istringstream(line);


        // Value holding the number of events
        int n;
        inp >> n;



        // Vector to hold the correct ordering
        std::vector<int> correct_ordering = std::vector<int>(n);

        // Next line contains the correct ordering of events
        for(int i = 0; i<n; i++) {
            int ordering;
            std::cin >> ordering;

            correct_ordering[i] = ordering;
        }

        // Vector to hold the vectors of attempts
        std::vector<std::vector<int>> attempts = std::vector<std::vector<int>>();

        std::string blank;
        std::getline(std::cin, blank);


        // Keep on getting inputs of the right size, then break.
        while(std::getline(std::cin, line)) {
            inp = std::istringstream(line);

            // Vector represeting the individual event.
            std::vector<int> attempt = std::vector<int>(n);
            int ordering;
            int i = 0;
            while(inp >> ordering) {
                attempt[ordering-1] = i;
                i++;
            }

            if(i != n) break;

            std::vector<int> lis_vec = std::vector<int>();

            for(int i = 0; i<n; i++) {
                // Initialize the DP array
                lis_vec.push_back(0);
            }
            lis_vec[0] = 1;

            int highest = 0;

            // Finding LIS
            for(int i = 0; i < n; i++) {
                int max = 0;
                for(int j = 0; j<i; j++) {
                    if(correct_ordering[attempt[j]] < correct_ordering[attempt[i]]){
                        if(lis_vec[j] > max) max = lis_vec[j];
                    }
                }
                lis_vec[i] = max+1;
                if(lis_vec[i] > highest) highest = lis_vec[i];

            }
            std::cout << highest << std::endl;

            attempts.push_back(attempt);
        }

    }
}

