#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stack>

int main() {
    int a;
    std::vector<int>sequence(0);

    // Tail contains a tuple with last element and corresponding list

    while(std::cin >> a) {
        sequence.push_back(a);
    }

    std::vector<int> tail(sequence.size(), 0);
    std::vector<int> indices(sequence.size(), -1);
    int len = 1;


    for(int i = 1; i<sequence.size(); i++) {

        // Check value less than first entry
        if(sequence[i] < sequence[tail[0]]) tail[0] = i;

            // Check value greater than last entry
        else if(sequence[tail[len-1]] < sequence[i]) {

            // In that case extend the longest sequence
            indices[i] = tail[len -1];
            tail[len++] = i;
        } else {

            // Find entry such that entry is less than value - use bc



            int start = -1;
            int end = (int) (len -1);


            while(end-start > 1) {

                int mid = start + (end - start)/2;

                if(sequence[tail[mid]] >= sequence[i]) {
                    end = mid;
                } else {
                    start = mid;
                }

            }

            // Update value
            indices[i] = tail[end-1];
            tail[end] = i;
        }

    }

    std::cout << len << std::endl << "-" << std::endl;
    std::stack<int> results = std::stack<int>();
    for(int i = tail[len-1]; i>=0; i = indices[i]) {
        results.push(sequence[i]);
    }
    while(!results.empty()) {
        std::cout << results.top() << std::endl;
        results.pop();
    }
}

