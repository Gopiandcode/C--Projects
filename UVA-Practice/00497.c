#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stack>

int main() {
    int test_cases;
    std::cin >> test_cases;
    std::string blank;
    std::getline(std::cin, blank);
    std::getline(std::cin, blank);
    for(int test_case_n = 0; test_case_n < test_cases; test_case_n++) {
        std::vector<int> sequence(0);

        while(1) {
            std::string line;
            std::getline(std::cin, line);
            if(line.length() == 0) break;

            int val;
            std::istringstream inp(line);
            inp >> val;
            sequence.push_back(val);
        }



        // Time to solve the problem using LIS
        std::vector<int> tails(sequence.size(), 0);
        std::vector<int> indices(sequence.size(), -1);
        int len = 1;

        for(int i = 1; i<sequence.size(); i++) {
            int val = sequence[i];

            if(val < sequence[tails[0]]) tails[0] = i;
            else if(val > sequence[tails[len-1]]) {
                indices[i] = tails[len-1];
                tails[len++] = i;
            }
            else {

                // Do a binary search to find the location to insert the value;
                int start = -1;
                int end = len-1;

                while(end-start > 1) {
                    int mid = start + (end-start)/2;
                    if(sequence[tails[mid]] >= val) {
                        end = mid;
                    } else {
                        start = mid;
                    }
                }

                indices[i] = tails[end-1];
                tails[end] = i;
            }

        }




        std::cout << "Max hits: " << len << std::endl;
        std::stack<int> s = std::stack<int>();
        int current = tails[len-1];
        while(current != -1) {
            s.push(sequence[current]);
            current = indices[current];
        }

        while(!s.empty()) {
            int val = s.top();
            std::cout << val << std::endl;
            s.pop();
        }
        if(test_case_n != test_cases-1)
            std::cout << std::endl;
    }
}

