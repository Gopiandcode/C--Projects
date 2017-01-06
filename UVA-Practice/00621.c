#include <iostream>
#include <string>
//+ S = 1, 4, 78
//- S35 -- 3 or 4
//* 9S4 -- 3 or 4
//? 190S -- 4 or 5
using std::string;


int parseSeq(const string& str) {
    string::size_type sz = str.size();
 if(sz<= 2) {
        if(str == "1" || str == "4" || str == "78") return 0;
        return -1;
 }
    if(str.substr(sz-2, sz) == "35") if(parseSeq(str.substr(0, sz-2)) != -1) return 1;
    if(str.substr(0,1) == "9" && str.substr(sz-1,sz) == "4") if(parseSeq(str.substr(1,sz-2)) != -1) return 2;
    if(str.substr(0, 3) == "190") if(parseSeq(str.substr(3,sz)) != -1) return 3;
    return -1;
}

int main() {
    int n;
    string val;
    std::cin>>n;
    while(n>0) {
        std::cin >> val;
        string out;
        int q = parseSeq(val);
        if(q == 0) out = "+";
        else if(q == 1) out = "-";
        else if(q == 2) out = "*";
        else if(q == 3) out = "?";
        if(q != -1) std::cout << out << std::endl;
        n--;
    }


    return 0;
}


