#include <iostream>
#include <string>
int main() {
    using std::string;
    int cases;
    string word;
    string one = "one";

    std::cin >> cases;
    while(cases>0){
        std::cin>>word;
        int val;
        if(word.size() == 3) {
            if((word[0] == one[0] && word[2] == one[2])||
                (word[0] == one[0] && word[1] == one[1])||
                (word[1] == one[1] && word[2] == one[2])) val = 1;
                else val = 2;
        }else val = 3;
        std::cout<<val<<std::endl;
        cases--;
    }
    return 0;
}
