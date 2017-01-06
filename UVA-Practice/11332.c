#include <iostream>
#include <string>
#include <math.h>
using std::string;
int simplify(int digits[], int sz) {
    if(sz == 1) return digits[0];
    int sum = 0;
    for(int i = 0; i<sz; i++) {
        sum += digits[i];
    }
    int nw_sz = (int)(log10(sum)+1);
    int out[nw_sz];
    int i = 0;
    while(i < nw_sz) {
        out[i] = sum%10;
        sum /= 10;
        i++;
    }

    return simplify(out, nw_sz);
}
int main() {
    string num;
    while(std::cin >> num, num!="0") {
        int digits[num.size()];
        for(int i = 0; i<num.size(); i++) digits[i] = num.at(i) -'0';
        int out = simplify(digits, num.size());
        std::cout<<out << std::endl;
    }


    return 0;
}
