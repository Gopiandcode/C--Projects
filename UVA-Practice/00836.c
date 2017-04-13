#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>



int main() {
    int test_case;
    std::cin >> test_case;

    // Loop over each test case
    for(int test = 0; test < test_case; test++) {
        std::string input;

        // First getline to get the end of the last buffered line
        if(!test) getline(std::cin, input);

        // Second getline to remove blank line as in specification
        if(!test) getline(std::cin, input);
        int row = 0;

        // Matrix vector to hold all sub arrays
        std::vector<std::vector<long long>> matrix = std::vector<std::vector<long long>>();

        // Get each line at a time to separate by rows
        // This is the input loop
        while(std::getline(std::cin, input), input.size() != 0) {

            // Column vector to hold each row
            std::vector<long long> column = std::vector<long long>();


            for(int ind = 0; ind < input.length(); ind++) {

                // Calculate the actual value of the
                long long val = input[ind] - '0';


                // if O then make the cell -infinity cost
                if(val == 0) val = -100000000000; // Division to prevent any overflow

                // Then calculate the sum of all values up to that index.
                if(row) val += matrix[row-1][ind];
                if(ind) val += column[ind-1];
                if(row && ind) val -= matrix[row-1][ind-1];




                // Put the value into the vector
                column.push_back(val);

            }

            // Once the row has been retrieved, add it to the vector
            matrix.push_back(column);
            row++;
        }


        // Now to run the computation - O(n^4) - ouch, but should not run into TLE

        long largest = 0;
        for(int start_i = 0; start_i < matrix.size(); start_i++)
            for(int start_j = 0; start_j < matrix[start_i].size(); start_j++)
                for(int end_i = start_i; end_i < matrix.size(); end_i++)
                    for(int end_j = start_j; end_j < matrix[end_i].size(); end_j++) {
                        // Don't waste time on already infinite sequences
                        if(end_i < 0 || end_j < 0 || start_i < 0 || start_j < 0) continue;
                        long long value = matrix[end_i][end_j];

                        // Subtract the starting positon sum, to get the submatrix sum
                        if(start_i) value -= matrix[start_i-1][end_j];
                        if(start_j) value -= matrix[end_i][start_j-1];
                        if(start_i && start_j) value += matrix[start_i-1][start_j-1];
                        if(largest < value) largest = value;
                    }
        
        // Print the result
        std::cout << largest <<std::endl;
        if(test != test_case-1) std::cout << std::endl;


    }

}

