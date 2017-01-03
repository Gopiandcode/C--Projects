#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <list>
#include <cstring>
double median(std::vector<double> vec);
std::vector<std::string> split(const std::string& str) ;

int main() {
    std::string input;
    std::string acc;
    while((std::cin >> input), input.size() > 1) {acc += input; acc += " ";}
    std::cout << acc;
    std::vector<std::string> words = split(acc);
    std::cout << "split complete" << std::endl;
    std::vector<std::string>::iterator iter = words.begin();

    while(iter != words.end()) std::cout << *iter++ << std::endl;

    return 0;
}
std::vector<std::string> split(const std::string& str) {
    typedef std::string::size_type intsz;
    intsz i = 0, j = 0;
    std::vector<std::string> ret;
    while(i != str.size()) {
        while(i != str.size() && isspace(str[i])) i++;
        j = i;
        while(j != str.size() && !isspace(str[j])) j++;
        if (j != i) ret.push_back(str.substr(i, j-i));
        else i++;
        i = j;
    }
    return ret;

}

double median(std::vector<double> vec) {
    typedef std::vector<double>::size_type vc_sz;
    vc_sz size = vec.size();
    if(size == 0) throw std::domain_error("median of an empty vector.");
    sort(vec.begin(), vec.end());
    vc_sz mid = size/2;
    return (size%2) ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}
/*
    std::cout << "#include <iostream>\n" << std::endl;
    std::cout << "int main() {" << std::endl;
    std::cout << "\tstd::out << \"Hello, World!\" << std::endl;" << std::endl;
    std::cout << "\treturn 0;" << std::endl;
    std::cout << "}" << std::endl;
*/


/*
    std::string name;
    std::cout << "Please enter your name?" << std::endl;
    std::cin >> name;
    std::string greeting = "Hello " + name + "!";
    std::string spaces(greeting.size(), ' ');
    std::string second = "* " + spaces + " *";
    std::string first(second.size(), '*');
    std::cout << first << "\n" << second << "\n" << "* " + greeting + " *" << "\n" <<second << "\n" << first;

*/

/*
    {const std::string s = "a string";

        {
            std::string x = s + ", really?";
            std::string s = "not a string";
            std::cout << x << std::endl;
        }
    }

*/
/*
    using std::vector;
    double x;
    vector<double> nums;
    std::cout << "Enter some numbers:" << std::endl;
    while(std::cin >> x) nums.push_back(x);
    std::cout << "Numbers got!" << std::endl;
    vector<double>::size_type items = nums.size();
    std::sort(nums.begin(), nums.end());
    double median = items % 2 ? ((nums[items/2] + nums[(items/2)-1])/2) : nums[items/2];
    std::cout << "The median of the numbers you entered is: " << median << std::endl;


*/


    /*
    for(int i = 0; i< 100; i++) {
        std::cout << std::setw(5);
        std::cout << i << ":" << i*i << std::endl;
    }*/



    /*
    std::vector<int> nums = {1,2,3,4,5};
    std::list<int> lolnums = {1,2,4,3,5};
    std::list<int>::const_iterator pos = lolnums.begin();
    lolnums.sort();
    for(std::vector<int>::size_type i = 0; i<nums.size(); i++) std::cout << std::setw(2) << nums[i] << ":" << std::setw(2) << *pos++ << std::endl;
    */
