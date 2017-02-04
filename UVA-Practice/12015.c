#include <iostream>
#include <string>
#include <vector>
int main()
{
    using std::string;
    using std::vector;
    int T, maximum = 0, relavence, current = 1;
    string link, current_link;
    vector<string> links;
    vector<int> nums;

    std::cin >> T;
    while(current <= T) {
        maximum = 0;
        std::cout << "Case #"<<current << ":"<<std::endl;
        for(int i = 0; i<10; i++) {
         std::cin >> current_link >> relavence;
         if(relavence > maximum) maximum = relavence;
         nums.push_back(relavence);
         links.push_back(current_link);
        }

        for(int i = 0; i<10; i++) {
            if(nums[i] == maximum) {
                std::cout << links[i]<<std::endl;
            }
        }
        links.clear();
        nums.clear();

        current++;
    }



    return 0;
}


